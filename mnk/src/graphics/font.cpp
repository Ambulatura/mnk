#include "mnkpch.h"
#include "font.h"

namespace mnk::graphics {

	Atlas::Atlas(const uint32_t width, const uint32_t height, const uint32_t channel)
		: Texture(width, height, channel), m_data(std::make_unique<uint8_t[]>(width * height)) {}

	Atlas::~Atlas() {}

	uint8_t* Atlas::GetData() const
	{
		return m_data.get();
	}

	Font::Font(const std::string& font_name, const std::string& font_path, const float font_size)
		: m_name(font_name), m_path(font_path), m_size(font_size), m_oversample_x(4), m_oversample_y(4), m_first_char(32), m_last_char(383),
		  m_char_count(m_last_char - m_first_char)
	{
		//ReadFont(m_path);
		fread(m_data, 1, 1 << 25, fopen(m_path.c_str(), "rb"));
		m_atlas = std::make_shared<Atlas>(3072, 3072, 'r');
		m_char_info = std::make_unique<stbtt_packedchar[]>(m_char_count);

		stbtt_pack_context context;
		if (!stbtt_PackBegin(&context, m_atlas->GetData(), m_atlas->GetWidth(), m_atlas->GetHeight(), 0, 1, nullptr))
			std::cout << "Failed to initialize font" << std::endl;

		stbtt_pack_range range;
		range.font_size = m_size;
		range.chardata_for_range = m_char_info.get();
		range.array_of_unicode_codepoints = NULL;
		range.first_unicode_codepoint_in_range = m_first_char;
		range.num_chars = m_last_char - m_first_char;

		stbtt_PackSetOversampling(&context, m_oversample_x, m_oversample_y);
		if (!stbtt_PackFontRanges(&context, (unsigned char*)m_data, 0, &range, 1))
			std::cout << "Failed to pack font" << std::endl;

		stbtt_PackEnd(&context);

		m_atlas->SetAtlasData(m_atlas->GetData());
	}

	Font::~Font()
	{
	/*	if (m_data != nullptr)
			delete[] m_data;*/
	}

	/*void Font::ReadFont(const std::string& file_path)
	{
		std::ifstream file(file_path, std::ifstream::binary);
		if (file) {
			file.seekg(0, file.end);
			auto length = file.tellg();
			file.seekg(0, file.beg);

			m_data = new char[length];
			file.read(m_data, length);
			if (file) {
				std::cout << "All characters read successfully!" << std::endl;
				file.close();
				return;
			}
			else {
				std::cout << "Error: only " << file.gcount() << " could be read!";
				file.close();
				return;
			}
		}
		std::cout << "Not file." << std::endl;
		return;
	}*/

	const stbtt_packedchar* Font::GetCharInfo() const
	{
		return m_char_info.get();
	}

	const uint32_t Font::GetFirstChar() const
	{
		return m_first_char;
	}

	const std::shared_ptr<Atlas> Font::GetAtlas() const
	{
		return m_atlas;
	}

	const std::string& Font::GetName() const
	{
		return m_name;
	}

	const float Font::GetSize() const
	{
		return m_size;
	}
}
