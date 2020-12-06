#pragma once

#include "common.h"
#include "vec4.h"
#include "vec3.h"

namespace mnk::math {
	
    struct MNK_API Mat4
    {
		Vec4 elements[4];

		Mat4();
		Mat4(float diagonal);
		Mat4(const Vec4& row0, const Vec4& row1, const Vec4& row2, const Vec4& row3);
		Mat4(const float e0,  const float e1,  const float e2,  const float e3,
			 const float e4,  const float e5,  const float e6,  const float e7,
			 const float e8,  const float e9,  const float e10, const float e11,
			 const float e12, const float e13, const float e14, const float e15);

		static Mat4 Identity();
		static Mat4 Transpose(const Mat4& mat4);

		Mat4* operator&();
		const float* operator&() const;

		Vec4& operator[](uint32_t index);
		Vec4 operator[](uint32_t index) const;

		static Mat4 Add(const Mat4& left, const Mat4& right);
		static Mat4 Substract(const Mat4& left, const Mat4& right);
		static Mat4 Multiply(const Mat4& left, const Mat4& right);

		Mat4& Add(const Mat4& mat4);
		Mat4& Substract(const Mat4& mat4);
		Mat4& Multiply(const Mat4& mat4);

		Mat4 operator+(const Mat4& mat4) const;
		Mat4 operator-(const Mat4& mat4) const;
		Mat4 operator*(const Mat4& mat4) const;
		
		Mat4& operator+=(const Mat4& mat4);
		Mat4& operator-=(const Mat4& mat4);
		Mat4& operator*=(const Mat4& mat4);

		Mat4 operator-() const;

		static Mat4 Add(const Mat4& mat4, const float t);
		static Mat4 Substract(const Mat4& mat4, const float t);
		static Mat4 Multiply(const Mat4& mat4, const float t);

		Mat4& Add(const float t);
		Mat4& Substract(const float t);
		Mat4& Multiply(const float t);

		friend Mat4 operator+(const Mat4& mat4, const float t);
		friend Mat4 operator-(const Mat4& mat4, const float t);
		friend Mat4 operator*(const Mat4& mat4, const float t);

		friend Mat4 operator+(const float t, const Mat4& mat4);
		friend Mat4 operator-(const float t, const Mat4& mat4);
		friend Mat4 operator*(const float t, const Mat4& mat4);

		Mat4& operator+=(const float t);
		Mat4& operator-=(const float t);
		Mat4& operator*=(const float t);

		Vec3 Multiply(const Vec3& vec3) const;
		Vec4 Multiply(const Vec4& vec4) const;

		Vec3 operator*(const Vec3& vec3) const;	
		Vec4 operator*(const Vec4& vec4) const;
		
		friend std::ostream& operator<<(std::ostream& stream, const Mat4& mat4);
    };

}
