#include "mnkpch.h"
#include "transform.h"

namespace mnk::transform {

	Mat4 Transform::Orthographic(const float left, const float right, const float bottom, const float top, const float near, const float far)
	{
		return Mat4::Transpose(Mat4(2.0f / (right - left), 0.0f,                  0.0f,                -(right + left) / (right - left),
									0.0f,                  2.0f / (top - bottom), 0.0f,                -(top + bottom) / (top - bottom),
									0.0f,                  0.0f,                 -2.0f / (far - near), -(far + near) / (far - near),
									0.0f,                  0.0f,                  0.0f,                 1.0f));
	}

	Mat4 Transform::Perspective(const float fovy, const float aspect, const float near, const float far)
	{
		float degree = fovy / 2.0f;
		float radian = degree_to_radian(degree);
		float d = cos(radian) / sin(radian);
		float A = -(far + near) / (far - near);
		float B = -(2.0f * far * near) / (far - near);

		return Mat4::Transpose(Mat4(d / aspect, 0.0f,  0.0f, 0.0f,
			                        0.0f,       d,     0.0f, 0.0f,
			                        0.0f,       0.0f,  A,    B,
			                        0.0f,       0.0f, -1.0f, 0.0f));
	}

	Mat4 Transform::Translate(const float tx, const float ty, const float tz)
	{
		return Mat4::Transpose(Mat4(1.0f, 0.0f, 0.0f, tx,
			                        0.0f, 1.0f, 0.0f, ty,
			                        0.0f, 0.0f, 1.0f, tz,
			                        0.0f, 0.0f, 0.0f, 1.0f));
	}

	Mat4 Transform::Scale(const float sx, const float sy, const float sz)
	{
		return Mat4::Transpose(Mat4(sx,   0.0f, 0.0f, 0.0f,
			                        0.0f, sy,   0.0f, 0.0f,
			                        0.0f, 0.0f, sz,   0.0f,
			                        0.0f, 0.0f, 0.0f, 1.0f));
	}

	Mat4 Transform::Rotate(const float degree, const Vec3& axis)
	{
		float radian = degree_to_radian(degree);
		float x = axis.x;
		float y = axis.y;
		float z = axis.z;
		float c = cos(radian);
		float s = sin(radian);
		float mc = 1.0f - c;

		return Mat4::Transpose(Mat4(c + mc * x * x,      mc * x * y + s * -z, mc * x * z + s * y,  0.0f,
			                        mc * x * y + s * z,  c + mc * y * y,      mc * y * z + s * -x, 0.0f,
			                        mc * x * z + s * -y, mc * y * z + s * x,  c + mc * z * z ,     0.0f,
			                        0.0f,                0.0f,                0.0f,                1.0f));
	}

}
