#include "mnkpch.h"
#include "layer.h"

namespace mnk::graphics {

	Layer::Layer(const std::shared_ptr<Renderer2D> renderer, const std::shared_ptr<Shader> shader, const Mat4& projection_matrix)
		: m_renderer(renderer), m_shader(shader), m_projection_matrix(projection_matrix)
	{
		m_shader->Bind();
		m_shader->SetUniformMatrix4f("u_projection", projection_matrix);
		m_shader->Unbind();
	}

	Layer::~Layer() {}

	void Layer::Add(const std::shared_ptr<Renderable2D> renderable)
	{
		m_renderables.push_back(renderable);
	}

	void Layer::Render() const
	{
		m_shader->Bind();
		m_renderer->Start();

		for (const auto& renderable : m_renderables) {
			//m_renderer->Submit(renderable);
			renderable->Submit(m_renderer);
		}

		m_renderer->End();
		m_shader->Unbind();
	}

	const std::vector<std::shared_ptr<Renderable2D>> Layer::GetRenderables() const
	{
		return m_renderables;
	}

}
