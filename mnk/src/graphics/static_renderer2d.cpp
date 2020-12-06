#include "mnkpch.h"
#include "static_renderer2d.h"

namespace mnk::graphics {
    
    StaticRenderer2D::StaticRenderer2D() {}

	StaticRenderer2D::~StaticRenderer2D() {}
    

	void StaticRenderer2D::Start()
	{
		started = true;
	}

    void StaticRenderer2D::Submit(const std::shared_ptr<Renderable2D> renderable)
    {
		m_renderables.push_back(std::static_pointer_cast<StaticSprite>(renderable));
    }

	void StaticRenderer2D::End()
	{
		if (started) {
			Flush();
			started = false;
		}
		else
			std::cout << "StaticRenderer2D isn't started!" << std::endl;
	}
    
    void StaticRenderer2D::Flush()
    {
        while (!m_renderables.empty()) {
            const auto& renderable = m_renderables.front();
            const auto& vertex_array = renderable->GetVertexArray();
            
            vertex_array->Bind();
			vertex_array->GetIndexBuffer()->Bind();
            glDrawElements(GL_TRIANGLES, vertex_array->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
			vertex_array->GetIndexBuffer()->Unbind();
            vertex_array->Unbind();
            
            m_renderables.pop_front();
        }
    }
    
}
