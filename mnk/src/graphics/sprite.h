#pragma once

#include "common.h"
#include "renderable2d.h"
#include "texture.h"

namespace mnk::graphics {

	class MNK_API Sprite : public Renderable2D
	{
	public:
		Sprite(const Vec3& position, const Vec2& size, const Vec4& color);
		Sprite(const Vec3& position, const Vec2& size, const std::shared_ptr<Texture> texture);
		Sprite::Sprite(const Vec3& position, const Vec2& size, const Vec4& color, const std::shared_ptr<Texture> texture);
		~Sprite();
	};

}
