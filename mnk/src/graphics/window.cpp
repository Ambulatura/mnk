#include "mnkpch.h"
#include "window.h"

namespace mnk::graphics {

	Window::Window(uint32_t width, uint32_t height, const char* name)
		: m_width(width), m_height(height), m_name(name)
	{
		if (!Init())
			glfwTerminate();

		memset(m_keys, false, MAX_KEYS);
		memset(m_mouse_buttons, false, MAX_BUTTONS);

		FontManager::Add(std::make_shared<Font>("Arial", "fonts/arial.ttf", 22)); // default font
		mnk::audio::SoundManager::Add(std::make_shared<mnk::audio::Sound>("Error", "sounds/error.mp3")); // default sound
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::Init()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

		/* Initialize the library */
		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		/* Create a windowed mode window and its OpenGL context */
		m_window = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		if (!m_window)
		{
			std::cout << "Failed to initialize window!" << std::endl;
			return false;
		}

		glfwSetKeyCallback(m_window, KeyCallback);
		glfwSetMouseButtonCallback(m_window, MouseButtonCallback);
		glfwSetCursorPosCallback(m_window, CursorPositionCallback);
		glfwSetFramebufferSizeCallback(m_window, WindowResizeCallback);
		glfwSetWindowUserPointer(m_window, this);

		glfwSwapBuffers(m_window);
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize OpenGL context!" << std::endl;
			return false;
		}

		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(OpenGLErrorCallback, NULL);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// glDepthMask(GL_TRUE);
		// glEnable(GL_DEPTH_TEST);
		// glDepthFunc(GL_LEQUAL);
		
		std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
		std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

		return true;
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	bool Window::Closed() const
	{
		return glfwWindowShouldClose(m_window) == 1;
	}

	uint32_t Window::GetWidth() const { return m_width; }
	uint32_t Window::GetHeight() const { return m_height; }

	bool Window::IsKeyPressed(const uint32_t key) const
	{
		if (key >= MAX_KEYS) {
			std::cout << "Key code out of range!" << std::endl;
			return false;
		}
		return m_keys[key];
	}

	bool Window::IsMouseButtonPressed(const uint32_t button) const
	{
		if (button >= MAX_KEYS) {
			std::cout << "Mouse button code out of range!" << std::endl;
			return false;
		}
		return m_mouse_buttons[button];
	}

	void Window::GetCursorPosition(double& x, double& y)
	{
		x = m_x;
		y = m_y;
	}

	void Window::ClearColor(float r, float g, float b, float a) const
	{
		glClearColor(r, g, b, a);
	}

	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		win->m_keys[key] = action != GLFW_RELEASE;
	}

	void Window::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		win->m_mouse_buttons[button] = action != GLFW_RELEASE;
	}

	void Window::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		win->m_x = xpos;
		win->m_y = ypos;
	}

	void Window::WindowResizeCallback(GLFWwindow* window, int width, int height)
	{
		Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		win->m_width = width;
		win->m_height = height;
		glViewport(0, 0, width, height);
	}

	void APIENTRY Window::OpenGLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * message, const void * userParam)
	{
		std::cout << "An error occurred!" << std::endl;
		std::cout << "Id: " << id << std::endl;
		std::cout << message << std::endl;
	}

}
