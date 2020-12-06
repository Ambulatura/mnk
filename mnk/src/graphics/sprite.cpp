#include "mnkpch.h"
#include "sprite.h"

namespace mnk::graphics {
	Sprite::Sprite(const Vec3& position, const Vec2& size, const Vec4& color)
		: Renderable2D(position, size, color) {}

	Sprite::Sprite(const Vec3& position, const Vec2& size, const std::shared_ptr<Texture> texture)
		: Renderable2D(position, size, texture) {}
	
	Sprite::Sprite(const Vec3& position, const Vec2& size, const Vec4& color, const std::shared_ptr<Texture> texture)
		: Renderable2D(position, size, color, texture) {}

	Sprite::~Sprite() {}
}
