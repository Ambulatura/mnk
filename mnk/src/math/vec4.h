#pragma once

#include "common.h"

namespace mnk::math {

	struct MNK_API Vec4
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

				union
				{
					float w, a;
				};
			};

			struct {
				float elements[4];
			};
		};

		Vec4();
		Vec4(const float x, const float y = 0.0f, const float z = 0.0f, const float w = 0.0f);

		const float* operator&() const;

		float& operator[](uint32_t index);
		float operator[](uint32_t index) const;

		static Vec4 Add(const Vec4& left, const Vec4& right);
		static Vec4 Substract(const Vec4& left, const Vec4& right);
		static Vec4 Multiply(const Vec4& left, const Vec4& right);
		static Vec4 Divide(const Vec4& left, const Vec4& right);

		Vec4& Add(const Vec4& vec);
		Vec4& Substract(const Vec4& vec);
		Vec4& Multiply(const Vec4& vec);
		Vec4& Divide(const Vec4& vec);

		Vec4 operator+(const Vec4& vec) const;
		Vec4 operator-(const Vec4& vec) const;
		Vec4 operator*(const Vec4& vec) const;
		Vec4 operator/(const Vec4& vec) const;

		Vec4& operator+=(const Vec4& vec);
		Vec4& operator-=(const Vec4& vec);
		Vec4& operator*=(const Vec4& vec);
		Vec4& operator/=(const Vec4& vec);

		Vec4 operator-() const;
		bool operator==(const Vec4& vec) const;
		bool operator!=(const Vec4& vec) const;

		static Vec4 Add(const Vec4& vec, const float t);
		static Vec4 Substract(const Vec4& vec, const float t);
		static Vec4 Multiply(const Vec4& vec, const float t);
		static Vec4 Divide(const Vec4& vec, const float t);

		Vec4& Add(const float t);
		Vec4& Substract(const float t);
		Vec4& Multiply(const float t);
		Vec4& Divide(const float t);

		friend Vec4 operator+(const Vec4& vec, const float t);
		friend Vec4 operator-(const Vec4& vec, const float t);
		friend Vec4 operator*(const Vec4& vec, const float t);
		friend Vec4 operator/(const Vec4& vec, const float t);

		friend Vec4 operator+(const float t, const Vec4& vec);
		friend Vec4 operator-(const float t, const Vec4& vec);
		friend Vec4 operator*(const float t, const Vec4& vec);
		friend Vec4 operator/(const float t, const Vec4& vec);

		Vec4& operator+=(const float t);
		Vec4& operator-=(const float t);
		Vec4& operator*=(const float t);
		Vec4& operator/=(const float t);

		friend std::ostream& operator<<(std::ostream& stream, const Vec4& vec);
	};

}
