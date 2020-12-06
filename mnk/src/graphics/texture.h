#pragma once

#include "common.h"
#include "glad/glad.h"
#include "other/stb_image.h"

namespace mnk::graphics {

	class MNK_API Texture
	{
	public:
		Texture(const uint32_t width, const uint32_t height);
		Texture(const std::string& file_path);
		~Texture();

		void Bind(const uint32_t slot = 0) const;
		void Unbind() const;

		void SetData(const void* data) const;
		void SetAtlasData(const void* data) const;
			
		uint32_t GetId() const;
		int32_t GetWidth() const;
		int32_t GetHeight() const;

	protected:
		Texture(const uint32_t width, const uint32_t height, const uint8_t channel);
		
	private:
		uint32_t m_id;
		uint8_t* m_texture_buffer;
		uint32_t m_internal_format;
		uint32_t m_format;
		int32_t m_width;
		int32_t m_height;
		int32_t m_bytes_per_pixel;
	};

}
