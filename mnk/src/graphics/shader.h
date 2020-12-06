#pragma once

#include "common.h"
#include "glad/glad.h"
#include "math/math.h"

namespace mnk::graphics {

	using namespace mnk::math;

	class MNK_API Shader
	{
	public:
		Shader(const std::string& vertex_path, const std::string& fragment_path);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void SetUniformInteger1i(const std::string& uniform_name, const int value);
		void SetUniformFloat1f(const std::string& uniform_name, const float value);
		void SetUniformFloat2f(const std::string& uniform_name, const Vec2& vec2);
		void SetUniformFloat3f(const std::string& uniform_name, const Vec3& vec3);
		void SetUniformFloat4f(const std::string& uniform_name, const Vec4& vec4);
		void SetUniformMatrix4f(const std::string& uniform_name, const Mat4& mat4);
		void SetUniformIntegerArray(const std::string& uniform_name, const int* values, uint32_t count);

	private:
		uint32_t m_id;
		std::string m_vertex_source;
		std::string m_fragment_source;
		std::unordered_map<std::string, int> m_uniform_cache;
	private:
		int GetUniformLocation(const std::string& uniform_name);
		std::string Parser(const std::string& shader_path) const;
		uint32_t Create() const;
		uint32_t Compile(const std::string& shader_source, const uint32_t shader_type) const;
	};
}
