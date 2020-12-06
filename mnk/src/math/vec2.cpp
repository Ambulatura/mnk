#include "mnkpch.h"
#include "vec2.h"

namespace mnk::math {

	Vec2::Vec2()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	Vec2::Vec2(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

	const float* Vec2::operator&() const
	{
		return &(this->elements[0]);
	}

	float& Vec2::operator[](uint32_t index)
	{
		if (index >= 2)
			std::cout << "Vec2 index out of range!" << std::endl;
		return this->elements[index];
	}

	float Vec2::operator[](uint32_t index) const
	{
		if (index >= 2)
			std::cout << "Vec2 index out of range!" << std::endl;
		return this->elements[index];
	}

	Vec2 Vec2::Add(const Vec2& left, const Vec2& right)
	{
		return Vec2(left.x + right.x, left.y + right.y);
	}

	Vec2 Vec2::Substract(const Vec2& left, const Vec2& right)
	{
		return Vec2(left.x - right.x, left.y - right.y);
	}

	Vec2 Vec2::Multiply(const Vec2& left, const Vec2& right)
	{
		return Vec2(left.x * right.x, left.y * right.y);
	}

	Vec2 Vec2::Divide(const Vec2& left, const Vec2& right)
	{
		return Vec2(left.x / right.x, left.y / right.y);
	}

	Vec2& Vec2::Add(const Vec2& vec)
	{
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	Vec2& Vec2::Substract(const Vec2& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;

		return *this;
	}

	Vec2& Vec2::Multiply(const Vec2& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;

		return *this;
	}

	Vec2& Vec2::Divide(const Vec2& vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;

		return *this;
	}

	Vec2 Vec2::operator+(const Vec2& vec) const
	{
		return Vec2::Add(*this, vec);
	}

	Vec2 Vec2::operator-(const Vec2& vec) const
	{
		return Vec2::Substract(*this, vec);
	}

	Vec2 Vec2::operator*(const Vec2& vec) const
	{
		return Vec2::Multiply(*this, vec);
	}

	Vec2 Vec2::operator/(const Vec2& vec) const
	{
		return Vec2::Divide(*this, vec);
	}

	Vec2& Vec2::operator+=(const Vec2& vec)
	{
		return this->Add(vec);
	}

	Vec2& Vec2::operator-=(const Vec2& vec)
	{
		return this->Substract(vec);
	}

	Vec2& Vec2::operator*=(const Vec2& vec)
	{
		return this->Multiply(vec);
	}

	Vec2& Vec2::operator/=(const Vec2& vec)
	{
		return this->Divide(vec);
	}

	Vec2 Vec2::operator-() const
	{
		return Vec2(-this->x, -this->y);
	}

	bool Vec2::operator==(const Vec2& vec) const
	{
		return (this->x == vec.x) && (this->y == vec.y);
	}

	bool Vec2::operator!=(const Vec2& vec) const
	{
		return !(*this == vec);
	}

	Vec2 Vec2::Add(const Vec2& vec, const float t)
	{
		return Vec2(vec.x + t, vec.y + t);
	}

	Vec2 Vec2::Substract(const Vec2& vec, const float t)
	{
		return Vec2(vec.x - t, vec.y - t);
	}

	Vec2 Vec2::Multiply(const Vec2& vec, const float t)
	{
		return Vec2(vec.x * t, vec.y * t);
	}

	Vec2 Vec2::Divide(const Vec2& vec, const float t)
	{
		return Vec2(vec.x / t, vec.y / t);
	}

	Vec2& Vec2::Add(const float t)
	{
		this->x += t;
		this->y += t;

		return *this;
	}

	Vec2& Vec2::Substract(const float t)
	{
		this->x -= t;
		this->y -= t;

		return *this;
	}

	Vec2& Vec2::Multiply(const float t)
	{
		this->x *= t;
		this->y *= t;

		return *this;
	}

	Vec2& Vec2::Divide(const float t)
	{
		this->x /= t;
		this->y /= t;

		return *this;
	}

	Vec2 operator+(const Vec2& vec, const float t)
	{
		return Vec2::Add(vec, t);
	}

	Vec2 operator-(const Vec2& vec, const float t)
	{
		return Vec2::Substract(vec, t);
	}

	Vec2 operator*(const Vec2& vec, const float t)
	{
		return Vec2::Multiply(vec, t);
	}

	Vec2 operator/(const Vec2& vec, const float t)
	{
		return Vec2::Divide(vec, t);
	}

	Vec2 operator+(const float t, const Vec2& vec)
	{
		return Vec2::Add(vec, t);
	}

	Vec2 operator-(const float t, const Vec2& vec)
	{
		return Vec2::Substract(vec, t);
	}

	Vec2 operator*(const float t, const Vec2& vec)
	{
		return Vec2::Multiply(vec, t);
	}

	Vec2 operator/(const float t, const Vec2& vec)
	{
		return Vec2::Divide(vec, t);
	}

	Vec2& Vec2::operator+=(const float t)
	{
		return this->Add(t);
	}

	Vec2& Vec2::operator-=(const float t)
	{
		return this->Substract(t);
	}

	Vec2& Vec2::operator*=(const float t)
	{
		return this->Multiply(t);
	}

	Vec2& Vec2::operator/=(const float t)
	{
		return this->Divide(t);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec2& vec)
	{
		stream << "(" << vec.x << ", " << vec.y << ")";

		return stream;
	}
}
