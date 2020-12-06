#pragma once

#include "common.h"
#include "math/mat4.h"
#include "math/vec3.h"
#include "utils/utils.h"

namespace mnk::transform {

	using namespace mnk::math;
	using namespace mnk::utils;

	struct MNK_API Transform
	{
		static Mat4 Orthographic(const float left, const float right,
			                     const float bottom, const float top,
			                     const float near = -1.0f, const float far = 1.0f);
		static Mat4 Perspective(const float fovy, const float aspect,
			                    const float near, const float far);
		static Mat4 Translate(const float tx = 0.0f, const float ty = 0.0f, const float tz = 0.0f);
		static Mat4 Scale(const float sx = 1.0f, const float sy = 1.0f, const float sz = 1.0f);
		static Mat4 Rotate(const float degree, const Vec3& axis);
	};
}
