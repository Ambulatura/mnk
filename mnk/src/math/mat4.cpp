#include "mnkpch.h"
#include "mat4.h"

namespace mnk::math {

	uint32_t min(uint32_t a, uint32_t b)
	{
		return (b < a) ? b : a;
	}
	
	Mat4::Mat4()
    {
		elements[0] = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
		elements[1] = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
		elements[2] = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
		elements[3] = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    Mat4::Mat4(float diagonal)
    {
		elements[0] = Vec4(diagonal, 0.0f,     0.0f,     0.0f);
		elements[1] = Vec4(0.0f,     diagonal, 0.0f,     0.0f);
		elements[2] = Vec4(0.0f,     0.0f,     diagonal, 0.0f);
		elements[3] = Vec4(0.0f,     0.0f,     0.0f,     diagonal);
    }

    Mat4::Mat4(const Vec4& row0, const Vec4& row1, const Vec4& row2, const Vec4& row3)
    {
		elements[0] = row0;
		elements[1] = row1;
		elements[2] = row2;
		elements[3] = row3;
    }

    Mat4::Mat4(const float e0, const float e1, const float e2, const float e3, 
			   const float e4, const float e5, const float e6, const float e7, 
			   const float e8, const float e9, const float e10, const float e11, 
			   const float e12, const float e13, const float e14, const float e15)
    {
		elements[0] = Vec4(e0,  e1,  e2,  e3);
		elements[1] = Vec4(e4,  e5,  e6,  e7);
		elements[2] = Vec4(e8,  e9,  e10, e11);
		elements[3] = Vec4(e12, e13, e14, e15);
    }

    Mat4 Mat4::Identity()
    {
		return Mat4(1.0f);
    }

    Mat4 Mat4::Transpose(const Mat4& mat4)
    {
		return Mat4(mat4[0][0], mat4[1][0], mat4[2][0], mat4[3][0],
					mat4[0][1], mat4[1][1], mat4[2][1], mat4[3][1],
					mat4[0][2], mat4[1][2], mat4[2][2], mat4[3][2],
					mat4[0][3], mat4[1][3], mat4[2][3], mat4[3][3]);
    }

	Mat4* Mat4::operator&()
	{
		return this;
	}
	
	const float* Mat4::operator&() const
    {
		return &(this->elements[0]);
    }

    Vec4& Mat4::operator[](uint32_t index)
    {
		if (index >= 4)
			std::cout << "Mat4 index out of range!" << std::endl;
		return this->elements[index];
    }

    Vec4 Mat4::operator[](uint32_t index) const
    {
		if (index >= 4)
			std::cout << "Mat4 index out of range!" << std::endl;
		return this->elements[index];
    }

    Mat4 Mat4::Add(const Mat4& left, const Mat4& right)
    {
		Mat4 mat4;

		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				mat4[i][j] = left[i][j] + right[i][j];

		return mat4;
    }

    Mat4 Mat4::Substract(const Mat4& left, const Mat4& right)
    {
		Mat4 mat4;

		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				mat4[i][j] = left[i][j] - right[i][j];

		return mat4;
    }

    Mat4 Mat4::Multiply(const Mat4& left, const Mat4& right)
    {
		Mat4 mat4;

		for (uint32_t i = 0; i < 4; i++) {
			for (uint32_t j = 0; j < 4; j++) {
				float sum = 0.0f;
				for (uint32_t k = 0; k < 4; k++) {
					sum += left[k][j] * right[i][k];
				}
				mat4[i][j] = sum;
			}
		}

		return mat4;
    }

    Mat4& Mat4::Add(const Mat4& mat4)
    {
		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				this->elements[i][j] += mat4[i][j];

		return *this;
    }

    Mat4& Mat4::Substract(const Mat4& mat4)
    {
		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				this->elements[i][j] -= mat4[i][j];

		return *this;
    }

    Mat4& Mat4::Multiply(const Mat4& mat4)
    {
		Mat4 m4;

		for (uint32_t i = 0; i < 4; i++) {
			for (uint32_t j = 0; j < 4; j++) {
				float sum = 0.0f;
				for (uint32_t k = 0; k < 4; k++) {
					sum += this->elements[k][j] * mat4[i][k];
				}
				m4[i][j] = sum;
			}
		}

		memcpy(this, &m4, 4 * 4 * 4);
		return *this;
    }

    Mat4 Mat4::operator+(const Mat4& mat4) const
    {
		return Mat4::Add(*this, mat4);
    }

    Mat4 Mat4::operator-(const Mat4& mat4) const
    {
		return Mat4::Substract(*this, mat4);
    }

    Mat4 Mat4::operator*(const Mat4& mat4) const
    {
		return Mat4::Multiply(*this, mat4);
    }

    Mat4& Mat4::operator+=(const Mat4& mat4)
    {
		return this->Add(mat4);
    }

    Mat4& Mat4::operator-=(const Mat4& mat4)
    {
		return this->Substract(mat4);
    }

    Mat4& Mat4::operator*=(const Mat4& mat4)
    {
		return this->Multiply(mat4);
    }

    Mat4 Mat4::operator-() const
    {
		Mat4 mat4;

		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				mat4[i][j] = -this->elements[i][j];

		return mat4;
    }

    Mat4 Mat4::Add(const Mat4& mat4, const float t)
    {
		Mat4 m4;

		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				mat4[i][j] += t;

		return m4;
    }

    Mat4 Mat4::Substract(const Mat4& mat4, const float t)
    {
		Mat4 m4;

		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				mat4[i][j] -= t;

		return m4;
    }

    Mat4 Mat4::Multiply(const Mat4& mat4, const float t)
    {
		Mat4 m4;

		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				mat4[i][j] *= t;

		return m4;
    }

    Mat4& Mat4::Add(const float t)
    {
		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				this->elements[i][j] += t;

		return *this;
    }

    Mat4& Mat4::Substract(const float t)
    {
		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				this->elements[i][j] -= t;

		return *this;
    }

    Mat4& Mat4::Multiply(const float t)
    {
		for (uint32_t i = 0; i < 4; i++)
			for (uint32_t j = 0; j < 4; j++)
				this->elements[i][j] *= t;

		return *this;
    }

    Mat4 operator+(const Mat4& mat4, const float t)
    {
		return Mat4::Add(mat4, t);
    }

    Mat4 operator-(const Mat4& mat4, const float t)
    {
		return Mat4::Substract(mat4, t);
    }

    Mat4 operator*(const Mat4& mat4, const float t)
    {
		return Mat4::Multiply(mat4, t);
    }

    Mat4 operator+(const float t, const Mat4& mat4)
    {
		return Mat4::Add(mat4, t);
    }

    Mat4 operator-(const float t, const Mat4& mat4)
    {
		return Mat4::Substract(mat4, t);
	}

	Mat4 operator*(const float t, const Mat4& mat4)
	{
		return Mat4::Multiply(mat4, t);
	}

	Mat4& Mat4::operator+=(const float t)
	{
		return this->Add(t);
	}

	Mat4& Mat4::operator-=(const float t)
	{
		return this->Substract(t);
	}

	Mat4& Mat4::operator*=(const float t)
	{
		return this->Multiply(t);
	}

	Vec3 Mat4::Multiply(const Vec3& vec3) const
	{
		return Vec3(this->elements[0][0] * vec3.elements[0] + this->elements[1][0] * vec3.elements[1] + this->elements[2][0] * vec3.elements[2] + this->elements[3][0],
					this->elements[0][1] * vec3.elements[0] + this->elements[1][1] * vec3.elements[1] + this->elements[2][1] * vec3.elements[2] + this->elements[3][1],
					this->elements[0][2] * vec3.elements[0] + this->elements[1][2] * vec3.elements[1] + this->elements[2][2] * vec3.elements[2] + this->elements[3][2]);
	}
	
	Vec4 Mat4::Multiply(const Vec4& vec4) const
	{
		return Vec4(this->elements[0][0] * vec4.elements[0] + this->elements[1][0] * vec4.elements[1] + this->elements[2][0] * vec4.elements[2] + this->elements[3][0] * vec4.elements[3],
					this->elements[0][1] * vec4.elements[0] + this->elements[1][1] * vec4.elements[1] + this->elements[2][1] * vec4.elements[2] + this->elements[3][1] * vec4.elements[3],
					this->elements[0][2] * vec4.elements[0] + this->elements[1][2] * vec4.elements[1] + this->elements[2][2] * vec4.elements[2] + this->elements[3][2] * vec4.elements[3],
					this->elements[0][3] * vec4.elements[0] + this->elements[1][3] * vec4.elements[1] + this->elements[2][3] * vec4.elements[2] + this->elements[3][3] * vec4.elements[3]);
	}

	Vec3 Mat4::operator*(const Vec3& vec3) const
	{
		return this->Multiply(vec3);
	}
	
	Vec4 Mat4::operator*(const Vec4& vec4) const
	{
		return this->Multiply(vec4);
	}
	
	std::ostream& operator<<(std::ostream& stream, const Mat4& mat4)
	{
		stream << mat4.elements[0] << std::endl;
		stream << mat4.elements[1] << std::endl;
		stream << mat4.elements[2] << std::endl;
		stream << mat4.elements[3];
	
		return stream;
	}

}
