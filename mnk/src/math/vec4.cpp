#include "mnkpch.h"
#include "vec4.h"

namespace mnk::math {

	Vec4::Vec4()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Vec4::Vec4(const float x, const float y, const float z, const float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	const float* Vec4::operator&() const
	{
		return &(this->elements[0]);
	}

	float& Vec4::operator[](uint32_t index)
	{
		if (index >= 4)
			std::cout << "Vec4 index out of range!" << std::endl;
		return this->elements[index];
	}

	float Vec4::operator[](uint32_t index) const
	{
		if (index >= 4)
			std::cout << "Vec4 index out of range!" << std::endl;
		return this->elements[index];
	}

	Vec4 Vec4::Add(const Vec4& left, const Vec4& right)
	{
		return Vec4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
	}

	Vec4 Vec4::Substract(const Vec4& left, const Vec4& right)
	{
		return Vec4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
	}

	Vec4 Vec4::Multiply(const Vec4& left, const Vec4& right)
	{
		return Vec4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
	}

	Vec4 Vec4::Divide(const Vec4& left, const Vec4& right)
	{
		return Vec4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
	}

	Vec4& Vec4::Add(const Vec4& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;
		this->w += vec.w;

		return *this;
	}

	Vec4& Vec4::Substract(const Vec4& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
		this->w -= vec.w;

		return *this;
	}

	Vec4& Vec4::Multiply(const Vec4& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;
		this->z *= vec.z;
		this->w *= vec.w;

		return *this;
	}

	Vec4& Vec4::Divide(const Vec4& vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;
		this->z /= vec.z;
		this->w /= vec.w;

		return *this;
	}

	Vec4 Vec4::operator+(const Vec4& vec) const
	{
		return Vec4::Add(*this, vec);
	}

	Vec4 Vec4::operator-(const Vec4& vec) const
	{
		return Vec4::Substract(*this, vec);
	}

	Vec4 Vec4::operator*(const Vec4& vec) const
	{
		return Vec4::Multiply(*this, vec);
	}

	Vec4 Vec4::operator/(const Vec4& vec) const
	{
		return Vec4::Divide(*this, vec);
	}

	Vec4& Vec4::operator+=(const Vec4& vec)
	{
		return this->Add(vec);
	}

	Vec4& Vec4::operator-=(const Vec4& vec)
	{
		return this->Substract(vec);
	}

	Vec4& Vec4::operator*=(const Vec4& vec)
	{
		return this->Multiply(vec);
	}

	Vec4& Vec4::operator/=(const Vec4& vec)
	{
		return this->Divide(vec);
	}

	Vec4 Vec4::operator-() const
	{
		return Vec4(-this->x, -this->y, -this->z, this->w);
	}

	bool Vec4::operator==(const Vec4& vec) const
	{
		return (this->x == vec.x) && (this->y == vec.y) && (this->z == vec.z) && (this->w == vec.w);
	}

	bool Vec4::operator!=(const Vec4& vec) const
	{
		return !(*this == vec);
	}

	Vec4 Vec4::Add(const Vec4& vec, const float t)
	{
		return Vec4(vec.x + t, vec.y + t, vec.z + t, vec.w + t);
	}

	Vec4 Vec4::Substract(const Vec4& vec, const float t)
	{
		return Vec4(vec.x - t, vec.y - t, vec.z - t, vec.w - t);
	}

	Vec4 Vec4::Multiply(const Vec4& vec, const float t)
	{
		return Vec4(vec.x * t, vec.y * t, vec.z * t, vec.w * t);
	}

	Vec4 Vec4::Divide(const Vec4& vec, const float t)
	{
		return Vec4(vec.x / t, vec.y / t, vec.z / t, vec.w / t);
	}

	Vec4& Vec4::Add(const float t)
	{
		this->x += t;
		this->y += t;
		this->z += t;
		this->w += t;

		return *this;
	}

	Vec4& Vec4::Substract(const float t)
	{
		this->x -= t;
		this->y -= t;
		this->z -= t;
		this->w -= t;

		return *this;
	}

	Vec4& Vec4::Multiply(const float t)
	{
		this->x *= t;
		this->y *= t;
		this->z *= t;
		this->w *= t;

		return *this;
	}

	Vec4& Vec4::Divide(const float t)
	{
		this->x /= t;
		this->y /= t;
		this->z /= t;
		this->w /= t;

		return *this;
	}

	Vec4 operator+(const Vec4& vec, const float t)
	{
		return Vec4::Add(vec, t);
	}

	Vec4 operator-(const Vec4& vec, const float t)
	{
		return Vec4::Substract(vec, t);
	}

	Vec4 operator*(const Vec4& vec, const float t)
	{
		return Vec4::Multiply(vec, t);
	}

	Vec4 operator/(const Vec4& vec, const float t)
	{
		return Vec4::Divide(vec, t);
	}

	Vec4 operator+(const float t, const Vec4& vec)
	{
		return Vec4::Add(vec, t);
	}

	Vec4 operator-(const float t, const Vec4& vec)
	{
		return Vec4::Substract(vec, t);
	}

	Vec4 operator*(const float t, const Vec4& vec)
	{
		return Vec4::Multiply(vec, t);
	}

	Vec4 operator/(const float t, const Vec4& vec)
	{
		return Vec4::Divide(vec, t);
	}

	Vec4& Vec4::operator+=(const float t)
	{
		return this->Add(t);
	}

	Vec4& Vec4::operator-=(const float t)
	{
		return this->Substract(t);
	}

	Vec4& Vec4::operator*=(const float t)
	{
		return this->Multiply(t);
	}

	Vec4& Vec4::operator/=(const float t)
	{
		return this->Divide(t);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec4& vec)
	{
		stream << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";

		return stream;
	}
}
