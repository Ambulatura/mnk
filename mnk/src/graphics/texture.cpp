#include "mnkpch.h"
#include "texture.h"

namespace mnk::graphics {

	Texture::Texture(const std::string& file_path)
		: m_texture_buffer(nullptr), m_width(0), m_height(0), m_bytes_per_pixel(0)
	{
		stbi_set_flip_vertically_on_load(1);
		m_texture_buffer = stbi_load(file_path.c_str(), &m_width, &m_height, &m_bytes_per_pixel, 4);
		glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
		glTextureStorage2D(m_id, 1, GL_RGBA8, m_width, m_height);
		glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(m_id, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_id, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureSubImage2D(m_id, 0, 0, 0, m_width, m_height, GL_RGBA, GL_UNSIGNED_BYTE, m_texture_buffer);
				
		stbi_image_free(m_texture_buffer);
	}

	Texture::Texture(const uint32_t width, const uint32_t height)
		: m_width(width), m_height(height)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
		glTextureStorage2D(m_id, 1, GL_RGBA8, m_width, m_height);
		glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(m_id, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_id, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	Texture::Texture(const uint32_t width, const uint32_t height, const uint8_t channel)
		: m_width(width), m_height(height) // for font atlas
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
		glTextureStorage2D(m_id, 1, GL_R8, m_width, m_height);
		/*glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(m_id, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTextureParameteri(m_id, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/
		glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	
	Texture::~Texture() {}

	void Texture::Bind(const uint32_t slot) const
	{
		// glActiveTexture(GL_TEXTURE0 + slot);
		// glBindTexture(GL_TEXTURE_2D, m_id);
		glBindTextureUnit(slot, m_id);
	}

	void Texture::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::SetData(const void* data) const
	{
		glTextureSubImage2D(m_id, 0, 0, 0, m_width, m_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	void Texture::SetAtlasData(const void* data) const
	{
		glTextureSubImage2D(m_id, 0, 0, 0, m_width, m_height, GL_RED, GL_UNSIGNED_BYTE, data);
	}
	
	uint32_t Texture::GetId() const
	{
		return m_id;
	}

	int32_t Texture::GetWidth() const
	{
		return m_width;
	}

	int32_t Texture::GetHeight() const
	{
		return m_height;
	}

}
