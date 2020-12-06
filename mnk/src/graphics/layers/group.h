#pragma once

#include "graphics/renderable2d.h"
#include "graphics/renderer2d.h"

namespace mnk::graphics {

	class MNK_API Group : public Renderable2D
	{
	public:
		Group(const Mat4& transformation_matrix);

		void Add(const std::shared_ptr<Renderable2D> renderable);
		void Submit(const std::shared_ptr<Renderer2D> renderer) override;
	private:
		std::vector<std::shared_ptr<Renderable2D>> m_renderables;
		Mat4 m_transformation_matrix;
	};
	
}
