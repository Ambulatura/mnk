#pragma once

#include "common.h"
#include "other/stb_truetype.h"
#include "glad/glad.h"
#include "texture.h"
#include <stdio.h>

namespace mnk::graphics {

	class MNK_API Atlas : public Texture
	{
	public:
		Atlas(const uint32_t width, const uint32_t height, const uint32_t channel);
		~Atlas();

		uint8_t* GetData() const;

	private:
		std::unique_ptr<uint8_t[]> m_data;
	};

	class MNK_API Font
		{
		public:
		Font(const std::string& font_name, const std::string& font_path, const float size);
		~Font();

		const stbtt_packedchar* GetCharInfo() const;
		const uint32_t GetFirstChar() const;
		const std::shared_ptr<Atlas> GetAtlas() const;
		const std::string& GetName() const;
		const float GetSize() const;
		
	private:
		std::shared_ptr<Atlas> m_atlas;
		std::unique_ptr<stbtt_packedchar[]> m_char_info;
		std::string m_name;
		std::string m_path;
		//char* m_data;
		unsigned char m_data[1 << 25];
		float m_size;
		uint32_t m_oversample_x;
		uint32_t m_oversample_y;
		uint32_t m_first_char;
		uint32_t m_last_char;
		uint32_t m_char_count;

	private:
		//void ReadFont(const std::string& file_path);
	};
}





