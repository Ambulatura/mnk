#pragma once

#include "common.h"
#include "renderer2d.h"
#include "renderable2d.h"
#include "texture.h"
#include "font.h"
#include "buffers/vertex_array.h"
#include "buffers/vertex_buffer.h"
#include "buffers/index_buffer.h"
#include "other/stb_truetype.h"
#include "utils/utils.h"

namespace mnk::graphics {

	struct VertexAttribute
	{
		Vec3 position;
		Vec4 color;
		Vec2 texture_coord;
		float texture_index;
	};

	struct BatchRenderer2DData
	{
		static const uint32_t MAX_SPRITES = 10000;
		static const uint32_t MAX_VERTICES = MAX_SPRITES * 4;
		static const uint32_t MAX_INDICES = MAX_SPRITES * 6;
		static const uint32_t MAX_TEXTURE_SLOTS = 32;

		std::unique_ptr<VertexArray> vertex_array;
		//std::unique_ptr<VertexBuffer> vertex_buffer;
		//std::unique_ptr<IndexBuffer> index_buffer;

		uint32_t index_count = 0;
		VertexAttribute* base_pointer = nullptr;
		VertexAttribute* buffer_pointer = nullptr;

		uint32_t texture_index = 1;
		std::array<std::shared_ptr<Texture>, MAX_TEXTURE_SLOTS> texture_slots;

		std::shared_ptr<Atlas> atlas;
		std::shared_ptr<Font> font;

		float glyph_offset_x = 0.0f;
		float glyph_offset_y = 0.0f;
		float text_offset_x = 0.0f;
		float text_offset_y = 0.0f;
	};

	static BatchRenderer2DData sprite_data;

	class MNK_API BatchRenderer2D : public Renderer2D
	{
	public:
		BatchRenderer2D();
		~BatchRenderer2D();

		void Start() override;
		void Submit(const std::shared_ptr<Renderable2D> renderable) override;
		void End() override;

		void SubmitText(const std::string& text, float offset_x, float offset_y, const Vec4& color, const std::shared_ptr<Font> font) override;
		
	private:
		void Flush() override;
		void SubmitGlyph(const uint32_t character, float offset_x, float offset_y, const Vec4& color) override;
	};

}
