#pragma once

#include "common.h"
#include "renderable2d.h"
#include "font_manager.h"

namespace mnk::graphics {

	class MNK_API Text : public Renderable2D
	{
	public:
		Text(const std::string& text, const float x, const float y, const Vec4& color, std::shared_ptr<Font> font);
		Text(const std::string& text, const float x, const float y, const Vec4& color, const std::string& font_name);
		Text(const std::string& text, const float x, const float y, const Vec4& color, const std::string& font_name, const float font_size);
		~Text();

		void Submit(const std::shared_ptr<Renderer2D> renderer) override;

	public:
		std::string text;

	private:
		std::shared_ptr<Font> m_font;
	};
}
