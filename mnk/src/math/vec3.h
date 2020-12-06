#pragma once

#include "common.h"

namespace mnk::math {

	struct MNK_API Vec3
	{
		union
		{
			struct
			{
				union
				{
					float x, r;
				};

				union
				{
					float y, g;
				};

				union
				{
					float z, b;
				};
			};

			struct {
				float elements[3];
			};
		};

		Vec3();
		Vec3(const float x, const float y = 0.0f, const float z = 0.0f);

		const float* operator&() const;

		float& operator[](uint32_t index);
		float operator[](uint32_t index) const;

		static Vec3 Add(const Vec3& left, const Vec3& right);
		static Vec3 Substract(const Vec3& left, const Vec3& right);
		static Vec3 Multiply(const Vec3& left, const Vec3& right);
		static Vec3 Divide(const Vec3& left, const Vec3& right);

		Vec3& Add(const Vec3& vec);
		Vec3& Substract(const Vec3& vec);
		Vec3& Multiply(const Vec3& vec);
		Vec3& Divide(const Vec3& vec);

		Vec3 operator+(const Vec3& vec) const;
		Vec3 operator-(const Vec3& vec) const;
		Vec3 operator*(const Vec3& vec) const;
		Vec3 operator/(const Vec3& vec) const;

		Vec3& operator+=(const Vec3& vec);
		Vec3& operator-=(const Vec3& vec);
		Vec3& operator*=(const Vec3& vec);
		Vec3& operator/=(const Vec3& vec);

		Vec3 operator-() const;
		bool operator==(const Vec3& vec) const;
		bool operator!=(const Vec3& vec) const;

		static Vec3 Add(const Vec3& vec, const float t);
		static Vec3 Substract(const Vec3& vec, const float t);
		static Vec3 Multiply(const Vec3& vec, const float t);
		static Vec3 Divide(const Vec3& vec, const float t);

		Vec3& Add(const float t);
		Vec3& Substract(const float t);
		Vec3& Multiply(const float t);
		Vec3& Divide(const float t);

		friend Vec3 operator+(const Vec3& vec, const float t);
		friend Vec3 operator-(const Vec3& vec, const float t);
		friend Vec3 operator*(const Vec3& vec, const float t);
		friend Vec3 operator/(const Vec3& vec, const float t);

		friend Vec3 operator+(const float t, const Vec3& vec);
		friend Vec3 operator-(const float t, const Vec3& vec);
		friend Vec3 operator*(const float t, const Vec3& vec);
		friend Vec3 operator/(const float t, const Vec3& vec);

		Vec3& operator+=(const float t);
		Vec3& operator-=(const float t);
		Vec3& operator*=(const float t);
		Vec3& operator/=(const float t);

		friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec);
	};

}
