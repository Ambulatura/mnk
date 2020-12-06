#pragma once

#include "common.h"

namespace mnk::math {

	struct MNK_API Vec2
	{
		union
		{
			struct
			{
				float x;
				float y;
			};

			struct {
				float elements[2];
			};
		};

		Vec2();
		Vec2(const float x, const float y = 0.0f);

		const float* operator&() const;

		float& operator[](uint32_t index);
		float operator[](uint32_t index) const;

		static Vec2 Add(const Vec2& left, const Vec2& right);
		static Vec2 Substract(const Vec2& left, const Vec2& right);
		static Vec2 Multiply(const Vec2& left, const Vec2& right);
		static Vec2 Divide(const Vec2& left, const Vec2& right);

		Vec2& Add(const Vec2& vec);
		Vec2& Substract(const Vec2& vec);
		Vec2& Multiply(const Vec2& vec);
		Vec2& Divide(const Vec2& vec);

		Vec2 operator+(const Vec2& vec) const;
		Vec2 operator-(const Vec2& vec) const;
		Vec2 operator*(const Vec2& vec) const;
		Vec2 operator/(const Vec2& vec) const;

		Vec2& operator+=(const Vec2& vec);
		Vec2& operator-=(const Vec2& vec);
		Vec2& operator*=(const Vec2& vec);
		Vec2& operator/=(const Vec2& vec);

		Vec2 operator-() const;
		bool operator==(const Vec2& vec) const;
		bool operator!=(const Vec2& vec) const;

		static Vec2 Add(const Vec2& vec, const float t);
		static Vec2 Substract(const Vec2& vec, const float t);
		static Vec2 Multiply(const Vec2& vec, const float t);
		static Vec2 Divide(const Vec2& vec, const float t);

		Vec2& Add(const float t);
		Vec2& Substract(const float t);
		Vec2& Multiply(const float t);
		Vec2& Divide(const float t);

		friend Vec2 operator+(const Vec2& vec, const float t);
		friend Vec2 operator-(const Vec2& vec, const float t);
		friend Vec2 operator*(const Vec2& vec, const float t);
		friend Vec2 operator/(const Vec2& vec, const float t);

		friend Vec2 operator+(const float t, const Vec2& vec);
		friend Vec2 operator-(const float t, const Vec2& vec);
		friend Vec2 operator*(const float t, const Vec2& vec);
		friend Vec2 operator/(const float t, const Vec2& vec);
		
		Vec2& operator+=(const float t);
		Vec2& operator-=(const float t);
		Vec2& operator*=(const float t);
		Vec2& operator/=(const float t);

		friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec);
	};

}
