#include "mnkpch.h"
#include "shader.h"

namespace mnk::graphics {

	Shader::Shader(const std::string& vertex_path, const std::string& fragment_path)
	{
		m_vertex_source = Parser(vertex_path);
		m_fragment_source = Parser(fragment_path);
		m_id = Create();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_id);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_id);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniformInteger1i(const std::string& uniform_name, const int value)
	{
		glUniform1i(GetUniformLocation(uniform_name), value);
	}

	void Shader::SetUniformFloat1f(const std::string& uniform_name, const float value)
	{
		glUniform1f(GetUniformLocation(uniform_name), value);
	}

	void Shader::SetUniformFloat2f(const std::string& uniform_name, const Vec2& vec2)
	{
		glUniform2f(GetUniformLocation(uniform_name), vec2.x, vec2.y);
	}

	void Shader::SetUniformFloat3f(const std::string& uniform_name, const Vec3& vec3)
	{
		glUniform3f(GetUniformLocation(uniform_name), vec3.x, vec3.y, vec3.z);
	}

	void Shader::SetUniformFloat4f(const std::string& uniform_name, const Vec4& vec4)
	{
		glUniform4f(GetUniformLocation(uniform_name), vec4.x, vec4.y, vec4.z, vec4.w);
	}

	void Shader::SetUniformMatrix4f(const std::string& uniform_name, const Mat4& mat4)
	{
		glUniformMatrix4fv(GetUniformLocation(uniform_name), 1, GL_FALSE, &mat4);
	}

	void Shader::SetUniformIntegerArray(const std::string& uniform_name, const int* values, uint32_t count)
	{
		glUniform1iv(GetUniformLocation(uniform_name), count, values);
	}
	
	int Shader::GetUniformLocation(const std::string& uniform_name)
	{
		if (m_uniform_cache.find(uniform_name) != m_uniform_cache.end()) {
			return m_uniform_cache[uniform_name];
		}

		int location = glGetUniformLocation(m_id, uniform_name.c_str());
		if (location == -1) 
			std::cout << "'" << uniform_name << "' uniform doesn't exist!" << std::endl;
		else 
			m_uniform_cache[uniform_name] = location;
		return location;
	}

	std::string Shader::Parser(const std::string& shader_path) const
	{
		std::ifstream file(shader_path);
		std::string line;
		std::string shader;
		while (std::getline(file, line))
			shader += line + '\n';
		file.close();
		return shader;
	}

	uint32_t Shader::Create() const
	{
		uint32_t program = glCreateProgram();
		uint32_t vs = Compile(m_vertex_source, GL_VERTEX_SHADER);
		uint32_t fs = Compile(m_fragment_source, GL_FRAGMENT_SHADER);
		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);

		int check;

		glGetProgramiv(program, GL_LINK_STATUS, &check);
		if (check == GL_FALSE) {
			char log[1024];
			int length;
			glGetProgramInfoLog(program, 1024, &length, log);
			std::cout << "Shader Linking Error!" << std::endl;
			std::cout << log << std::endl;
			glDeleteShader(vs);
			glDeleteShader(fs);
			glDeleteProgram(program);
			return 0;
		}

		glValidateProgram(program);

		glGetProgramiv(program, GL_VALIDATE_STATUS, &check);
		if (check == GL_FALSE) {
			char log[1024];
			int length;
			glGetProgramInfoLog(program, 1024, &length, log);
			std::cout << "Shader Validation Error!" << std::endl;
			std::cout << log << std::endl;
			glDeleteShader(vs);
			glDeleteShader(fs);
			glDeleteProgram(program);
		}

		glDeleteShader(vs);
		glDeleteShader(fs);
		return program;
	}

	uint32_t Shader::Compile(const std::string& shader_source, const uint32_t shader_type) const
	{
		uint32_t shader = glCreateShader(shader_type);
		const char* c_shader_source = shader_source.c_str();
		glShaderSource(shader, 1, &c_shader_source, nullptr);
		glCompileShader(shader);

		int compiled;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE) {
			char log[1024];
			int length;
			glGetShaderInfoLog(shader, 1024, &length, log);
			std::cout << (shader_type == GL_VERTEX_SHADER ? "[Vertex" : "[Fragment") << " Shader] Compile Error!" << std::endl;
			std::cout << log << std::endl;
			glDeleteShader(shader);
			return 0;
		}

		return shader;
	}
}
