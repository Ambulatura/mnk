#pragma once

#include "common.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "font_manager.h"
#include "audio/sound_manager.h"

#define MAX_KEYS    1024
#define MAX_BUTTONS 32

namespace mnk::graphics {

	class MNK_API Window
	{
	public:
		Window(uint32_t width, uint32_t height, const char* name);
		~Window();

		void Update();
		bool Closed() const;

		uint32_t GetWidth() const;
		uint32_t GetHeight() const;

		bool IsKeyPressed(const uint32_t key) const;
		bool IsMouseButtonPressed(const uint32_t button) const;
		void GetCursorPosition(double& x, double& y);

		void ClearColor(float r, float g, float b, float a) const;

		void Clear() const;

	private:
		GLFWwindow* m_window;
		uint32_t m_width;
		uint32_t m_height;
		const char* m_name;

		uint8_t m_keys[MAX_KEYS];
		uint8_t m_mouse_buttons[MAX_BUTTONS];
		double m_x;
		double m_y;

	private:
		bool Init();
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void WindowResizeCallback(GLFWwindow* window, int width, int height);
		static void APIENTRY OpenGLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
	};

}
