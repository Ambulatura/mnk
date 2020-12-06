#include "mnkpch.h"
#include "group.h"

namespace mnk::graphics {

	Group::Group(const Mat4& transformation_matrix)
		: Renderable2D(), m_transformation_matrix(transformation_matrix) {}

	void Group::Add(const std::shared_ptr<Renderable2D> renderable)
	{
		m_renderables.push_back(renderable);
	}

	void Group::Submit(const std::shared_ptr<Renderer2D> renderer)
	{
		renderer->Push(m_transformation_matrix);
		
		for (const auto renderable : m_renderables)	{
			renderable->Submit(renderer);
		}
		
		renderer->Pop();
	}
}
