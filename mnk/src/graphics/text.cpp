#include "mnkpch.h"
#include "text.h"

namespace mnk::graphics {

	Text::Text(const std::string& text, const float x, const float y, const Vec4& color, std::shared_ptr<Font> font)
		: Renderable2D(), text(text), m_font(font)
	{
		m_position = Vec3(x, y);
		m_color = color;
	}

	Text::Text(const std::string& text, const float x, const float y, const Vec4& color, const std::string& font_name)
		: Renderable2D(), text(text), m_font(FontManager::Get(font_name))
	{
		m_position = Vec3(x, y);
		m_color = color;
	}

	Text::Text(const std::string& text, const float x, const float y, const Vec4& color, const std::string& font_name, const float font_size)
		: Renderable2D(), text(text), m_font(FontManager::Get(font_name, font_size))
	{
		m_position = Vec3(x, y);
		m_color = color;
	}
	
	Text::~Text() {}

	void Text::Submit(const std::shared_ptr<Renderer2D> renderer)
	{
		renderer->SubmitText(text, m_position.x, m_position.y, m_color, m_font);
	}
}
