#include "mnkpch.h"
#include "batch_renderer2d.h"

namespace mnk::graphics {

	BatchRenderer2D::BatchRenderer2D()
	{
		sprite_data.base_pointer = new VertexAttribute[sprite_data.MAX_VERTICES];

		uint32_t* indices = new uint32_t[sprite_data.MAX_INDICES];
		uint32_t offset = 0;
		for (uint32_t i = 0; i < sprite_data.MAX_INDICES; i += 6)
		{
			indices[i + 0] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		sprite_data.vertex_array = std::make_unique<VertexArray>();
		auto vertex_buffer = std::make_unique<VertexBuffer>(sprite_data.MAX_VERTICES * sizeof(VertexAttribute));
		vertex_buffer->SetVertexBufferLayout({
				{"l_position", GL_FLOAT, 3, false},
				{"l_color", GL_FLOAT, 4, false},
				{"l_texture", GL_FLOAT, 2, false},
				{"l_texture_id", GL_FLOAT, 1, false},
			});

		auto index_buffer = std::make_unique<IndexBuffer>(indices, sprite_data.MAX_INDICES);
		sprite_data.vertex_array->AddVertexBuffer(std::move(vertex_buffer));
		sprite_data.vertex_array->SetIndexBuffer(std::move(index_buffer));

		delete[] indices;

		auto white_texture = std::make_shared<Texture>(1, 1);
		uint32_t white = 0xffffff;
		white_texture->SetData(&white);

		sprite_data.texture_slots[0] = white_texture;
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		if (sprite_data.base_pointer != nullptr)
			delete[] sprite_data.base_pointer;
	}

	void BatchRenderer2D::Start()
	{
		sprite_data.index_count = 0;
		sprite_data.buffer_pointer = sprite_data.base_pointer;

		sprite_data.texture_index = 1;
	}

	void BatchRenderer2D::Submit(const std::shared_ptr<Renderable2D> renderable)
	{
		Vec3 position = renderable->GetPosition();
		Vec2 size = renderable->GetSize();
		Vec4 color = renderable->GetColor();
		auto texture = renderable->GetTexture();

		if (sprite_data.index_count >= sprite_data.MAX_INDICES) {
			End();
			Start();
		}
		
		float texture_index = 0.0f;
		if (texture) {
			for (uint32_t i = 1; i < sprite_data.texture_index; i++) {
				if (sprite_data.texture_slots[i]->GetId() == texture->GetId()) {
					texture_index = (float)(i);
					break;
				}
			}

			if (texture_index == 0.0f) {
				if (sprite_data.texture_index >= sprite_data.MAX_TEXTURE_SLOTS) {
					End();
					Start();
				}

				texture_index = (float)sprite_data.texture_index;
				sprite_data.texture_slots[sprite_data.texture_index] = texture;
				sprite_data.texture_index++;
			}
		}
		
		sprite_data.buffer_pointer->position = *m_transformation_back * position;
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(0.0f, 0.0f);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.buffer_pointer->position = *m_transformation_back * Vec3(position.x + size.x, position.y);
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(1.0f, 0.0f);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.buffer_pointer->position = *m_transformation_back * Vec3(position.x + size.x, position.y + size.y);
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(1.0f, 1.0f);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.buffer_pointer->position = *m_transformation_back * Vec3(position.x, position.y + size.y);
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(0.0f, 1.0f);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.index_count += 6;
	}

	void BatchRenderer2D::SubmitGlyph(const uint32_t character, float offset_x, float offset_y, const Vec4& color)
	{
		stbtt_aligned_quad quad;

		stbtt_GetPackedQuad(sprite_data.font->GetCharInfo(), sprite_data.atlas->GetWidth(), sprite_data.atlas->GetHeight(), character - sprite_data.font->GetFirstChar(), &offset_x, &offset_y, &quad, 1);

		sprite_data.glyph_offset_x = offset_x;
		sprite_data.glyph_offset_y = offset_y;

		float texture_index = 0.0f;
		if (sprite_data.atlas) {
			for (uint32_t i = 1; i < sprite_data.texture_index; i++) {
				if (sprite_data.texture_slots[i]->GetId() == sprite_data.atlas->GetId()) {
					texture_index = (float)(i);
					break;
				}
			}

			if (texture_index == 0.0f) {
				if (sprite_data.texture_index >= sprite_data.MAX_TEXTURE_SLOTS) {
					End();
					Start();
				}

				texture_index = (float)sprite_data.texture_index;
				sprite_data.texture_slots[sprite_data.texture_index] = sprite_data.atlas;
				sprite_data.texture_index++;
			}
		}

		float scale_x = 1.0f;// 32.0f / 960.0f;
		float scale_y = 1.0f;//18.0f / 540.0f;
		
		sprite_data.buffer_pointer->position = *m_transformation_back * Vec3(quad.x0 * scale_x, -quad.y0 * scale_y);
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(quad.s0, quad.t0);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.buffer_pointer->position = *m_transformation_back * Vec3(quad.x1 * scale_x, -quad.y0 * scale_y);
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(quad.s1, quad.t0);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.buffer_pointer->position = *m_transformation_back * Vec3(quad.x1 * scale_x, -quad.y1 * scale_y);
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(quad.s1, quad.t1);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.buffer_pointer->position = *m_transformation_back * Vec3(quad.x0 * scale_x, -quad.y1 * scale_y);
		sprite_data.buffer_pointer->color = color;
		sprite_data.buffer_pointer->texture_coord = Vec2(quad.s0, quad.t1);
		sprite_data.buffer_pointer->texture_index = texture_index;
		sprite_data.buffer_pointer++;

		sprite_data.index_count += 6;
	}

	void BatchRenderer2D::SubmitText(const std::string& text, float offset_x, float offset_y, const Vec4& color, const std::shared_ptr<Font> font)
	{
		using namespace mnk::utils;
		
		sprite_data.font = font;
		sprite_data.atlas = font->GetAtlas();
		
		sprite_data.text_offset_x = offset_x;
		sprite_data.text_offset_y = -offset_y;

		for (uint32_t i = 0; i < text.length(); i += length_of_utf8_char(*(uint32_t*)&(text[i]))) {
			uint32_t* glyph = (uint32_t*)&(text[i]);
			SubmitGlyph(convert_utf8_to_codepoint(*glyph), sprite_data.text_offset_x, sprite_data.text_offset_y, color);
			sprite_data.text_offset_x = sprite_data.glyph_offset_x;
			sprite_data.text_offset_y = sprite_data.glyph_offset_y;
		}

		sprite_data.text_offset_x = 0.0f;
		sprite_data.text_offset_y = 0.0f;
		sprite_data.glyph_offset_x = 0.0f;
		sprite_data.glyph_offset_y = 0.0f;
	}

	void BatchRenderer2D::End()
	{
		Flush();
	}

	void BatchRenderer2D::Flush()
	{
		uint32_t size = (uint32_t)((uint8_t*)sprite_data.buffer_pointer - (uint8_t*)sprite_data.base_pointer);
		sprite_data.vertex_array->GetVertexBuffers()[0]->SetData(sprite_data.base_pointer, size);

		for (uint32_t i = 0; i < sprite_data.texture_index; i++) {
			sprite_data.texture_slots[i]->Bind(i);
		}

		glDrawElements(GL_TRIANGLES, sprite_data.index_count, GL_UNSIGNED_INT, nullptr);
	}

}
