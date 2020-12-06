#pragma once

#include "common.h"
#include <array>
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "renderer2d.h"
#include "texture.h"

namespace mnk::graphics {

    using mnk::math::Vec2;
    using mnk::math::Vec3;
    using mnk::math::Vec4;

    class MNK_API Renderable2D : public std::enable_shared_from_this<Renderable2D>
    {
	public:
		virtual	void Submit(const std::shared_ptr<Renderer2D> renderer)
		{
			renderer->Submit(shared_from_this());
		}
	
		inline const Vec3& GetPosition() const { return m_position; }
		inline const Vec2& GetSize() const { return m_size; }
		inline const Vec4& GetColor() const { return m_color; }
		inline const std::shared_ptr<Texture>& GetTexture() const { return m_texture; }

		inline void SetPosition(const Vec3& position) { m_position = position; }
		inline void SetSize(const Vec2& size) { m_size = size; }
		inline void SetColor(const Vec4& color) { m_color = color; }
		inline void SetTexture(const std::shared_ptr<Texture> texture) { m_texture = texture; }

	protected:
		Renderable2D(const Vec3& position, const Vec2& size, const Vec4& color) : m_position(position), m_size(size), m_color(color), m_texture(nullptr) {}

		Renderable2D(const Vec3& position, const Vec2& size, const std::shared_ptr<Texture>& texture) : m_position(position), m_size(size), m_color(0), m_texture(texture) {}

		Renderable2D(const Vec3& position, const Vec2& size, const Vec4& color, const std::shared_ptr<Texture>& texture) : m_position(position), m_size(size), m_color(color), m_texture(texture) {}
		
		Renderable2D() {} // Group, Text
		
		virtual ~Renderable2D() {}
		
	protected:
		Vec3 m_position;
		Vec2 m_size;
		Vec4 m_color;
		std::shared_ptr<Texture> m_texture;
	};

}











