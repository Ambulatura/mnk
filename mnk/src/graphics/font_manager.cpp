#include "mnkpch.h"
#include "font_manager.h"

namespace mnk::graphics {

	std::vector<std::shared_ptr<Font>> FontManager::m_fonts;

	void FontManager::Add(std::shared_ptr<Font> font)
	{
		m_fonts.push_back(font);
	}

	std::shared_ptr<Font> FontManager::Get(const std::string& font_name)
	{
		for (const auto font : m_fonts) {
			if (font->GetName() == font_name)
				return font;
		}
		std::cout << "Font (" << font_name << ") could not find. The default font (" << m_fonts[0]->GetName() << ") has been enabled." << std::endl;
		return m_fonts[0];
	}

	std::shared_ptr<Font> FontManager::Get(const std::string& font_name, float font_size)
	{
		for (const auto font : m_fonts) {
			if (font->GetName() == font_name && font->GetSize() == font_size)
				return font;
		}
		std::cout << "Font (" << font_name << "-" << font_size << ") could not find. The default font (" << m_fonts[0]->GetName() << "-" << m_fonts[0]->GetSize() << ") has been enabled." << std::endl;
		return m_fonts[0];
	}

}
