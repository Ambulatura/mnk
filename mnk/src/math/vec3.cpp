#include "mnkpch.h"
#include "vec3.h"

namespace mnk::math {

	Vec3::Vec3()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	Vec3::Vec3(const float x, const float y, const float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	const float* Vec3::operator&() const
	{
		return &(this->elements[0]);
	}

	float& Vec3::operator[](uint32_t index)
	{
		if (index >= 3)
			std::cout << "Vec3 index out of range!" << std::endl;
		return this->elements[index];
	}

	float Vec3::operator[](uint32_t index) const
	{
		if (index >= 3)
			std::cout << "Vec3 index out of range!" << std::endl;
		return this->elements[index];
	}

	Vec3 Vec3::Add(const Vec3& left, const Vec3& right)
	{
		return Vec3(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	Vec3 Vec3::Substract(const Vec3& left, const Vec3& right)
	{
		return Vec3(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	Vec3 Vec3::Multiply(const Vec3& left, const Vec3& right)
	{
		return Vec3(left.x * right.x, left.y * right.y, left.z * right.z);
	}

	Vec3 Vec3::Divide(const Vec3& left, const Vec3& right)
	{
		return Vec3(left.x / right.x, left.y / right.y, left.z / right.z);
	}

	Vec3& Vec3::Add(const Vec3& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;

		return *this;
	}

	Vec3& Vec3::Substract(const Vec3& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;

		return *this;
	}

	Vec3& Vec3::Multiply(const Vec3& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;
		this->z *= vec.z;

		return *this;
	}

	Vec3& Vec3::Divide(const Vec3& vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;
		this->z /= vec.z;

		return *this;
	}

	Vec3 Vec3::operator+(const Vec3& vec) const
	{
		return Vec3::Add(*this, vec);
	}

	Vec3 Vec3::operator-(const Vec3& vec) const
	{
		return Vec3::Substract(*this, vec);
	}

	Vec3 Vec3::operator*(const Vec3& vec) const
	{
		return Vec3::Multiply(*this, vec);
	}

	Vec3 Vec3::operator/(const Vec3& vec) const
	{
		return Vec3::Divide(*this, vec);
	}

	Vec3& Vec3::operator+=(const Vec3& vec)
	{
		return this->Add(vec);
	}

	Vec3& Vec3::operator-=(const Vec3& vec)
	{
		return this->Substract(vec);
	}

	Vec3& Vec3::operator*=(const Vec3& vec)
	{
		return this->Multiply(vec);
	}

	Vec3& Vec3::operator/=(const Vec3& vec)
	{
		return this->Divide(vec);
	}

	Vec3 Vec3::operator-() const
	{
		return Vec3(-this->x, -this->y, -this->z);
	}

	bool Vec3::operator==(const Vec3& vec) const
	{
		return (this->x == vec.x) && (this->y == vec.y) && (this->z == vec.z);
	}

	bool Vec3::operator!=(const Vec3& vec) const
	{
		return !(*this == vec);
	}

	Vec3 Vec3::Add(const Vec3& vec, const float t)
	{
		return Vec3(vec.x + t, vec.y + t, vec.z + t);
	}

	Vec3 Vec3::Substract(const Vec3& vec, const float t)
	{
		return Vec3(vec.x - t, vec.y - t, vec.z - t);
	}

	Vec3 Vec3::Multiply(const Vec3& vec, const float t)
	{
		return Vec3(vec.x * t, vec.y * t, vec.z * t);
	}

	Vec3 Vec3::Divide(const Vec3& vec, const float t)
	{
		return Vec3(vec.x / t, vec.y / t, vec.z / t);
	}

	Vec3& Vec3::Add(const float t)
	{
		this->x += t;
		this->y += t;
		this->z += t;

		return *this;
	}

	Vec3& Vec3::Substract(const float t)
	{
		this->x -= t;
		this->y -= t;
		this->z -= t;

		return *this;
	}

	Vec3& Vec3::Multiply(const float t)
	{
		this->x *= t;
		this->y *= t;
		this->z *= t;

		return *this;
	}

	Vec3& Vec3::Divide(const float t)
	{
		this->x /= t;
		this->y /= t;
		this->z /= t;

		return *this;
	}

	Vec3 operator+(const Vec3& vec, const float t)
	{
		return Vec3::Add(vec, t);
	}

	Vec3 operator-(const Vec3& vec, const float t)
	{
		return Vec3::Substract(vec, t);
	}

	Vec3 operator*(const Vec3& vec, const float t)
	{
		return Vec3::Multiply(vec, t);
	}

	Vec3 operator/(const Vec3& vec, const float t)
	{
		return Vec3::Divide(vec, t);
	}

	Vec3 operator+(const float t, const Vec3& vec)
	{
		return Vec3::Add(vec, t);
	}

	Vec3 operator-(const float t, const Vec3& vec)
	{
		return Vec3::Substract(vec, t);
	}

	Vec3 operator*(const float t, const Vec3& vec)
	{
		return Vec3::Multiply(vec, t);
	}

	Vec3 operator/(const float t, const Vec3& vec)
	{
		return Vec3::Divide(vec, t);
	}

	Vec3& Vec3::operator+=(const float t)
	{
		return this->Add(t);
	}

	Vec3& Vec3::operator-=(const float t)
	{
		return this->Substract(t);
	}

	Vec3& Vec3::operator*=(const float t)
	{
		return this->Multiply(t);
	}

	Vec3& Vec3::operator/=(const float t)
	{
		return this->Divide(t);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec3& vec)
	{
		stream << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";

		return stream;
	}
}
