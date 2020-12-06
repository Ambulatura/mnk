#pragma once

#include "common.h"
#include "graphics/renderable2d.h"
#include "graphics/renderer2d.h"
#include "graphics/shader.h"
#include "transform/transform.h"

namespace mnk::graphics {

	using namespace mnk::transform;

	class MNK_API Layer
	{
	public:
		virtual ~Layer();

		virtual void Add(const std::shared_ptr<Renderable2D> renderable);
		virtual void Render() const;

		const std::vector<std::shared_ptr<Renderable2D>> GetRenderables() const;

	protected:
		std::shared_ptr<Renderer2D> m_renderer;
		std::vector<std::shared_ptr<Renderable2D>> m_renderables;
		std::shared_ptr<Shader> m_shader;
		Mat4 m_projection_matrix;

	protected:
		Layer(const std::shared_ptr<Renderer2D> renderer, const std::shared_ptr<Shader> shader, const Mat4& projection_matrix);
	};

}
