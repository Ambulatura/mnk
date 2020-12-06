#pragma once

#include "common.h"
#include "font.h"

namespace mnk::graphics {

	class MNK_API FontManager
	{
	public:
		static void Add(std::shared_ptr<Font> font);
		static std::shared_ptr<Font> Get(const std::string& font_name);
		static std::shared_ptr<Font> Get(const std::string& font_name, float size);
	private:
		FontManager() {}
		static std::vector<std::shared_ptr<Font>> m_fonts;
	};
	
}
