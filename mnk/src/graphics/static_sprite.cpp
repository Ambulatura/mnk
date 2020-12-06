#include "mnkpch.h"
#include "static_sprite.h"

namespace mnk::graphics {
    
    StaticSprite::StaticSprite(const Vec3& position, const Vec2& size, const Vec4& color)
        : Renderable2D(position, size, color)
    {
        float vertices[] = {
            position.x,          position.y,          position.z, color.r, color.g, color.b, color.a,
            position.x + size.x, position.y,          position.z, color.r, color.g, color.b, color.a,
            position.x + size.x, position.y + size.y, position.z, color.r, color.g, color.b, color.a,
            position.x,          position.y + size.y, position.z, color.r, color.g, color.b, color.a,
        };
        
        uint32_t indices[] = {
            0, 1, 2,
            2, 3, 0,
        };
        
        m_vertex_array = std::make_shared<VertexArray>();
        auto vertex_buffer = std::make_unique<VertexBuffer>(vertices, sizeof(vertices));
        auto index_buffer = std::make_unique<IndexBuffer>(indices, 6);
        vertex_buffer->SetVertexBufferLayout({{"l_position", GL_FLOAT, 3, false}, {"l_color", GL_FLOAT, 4, false}});
        m_vertex_array->AddVertexBuffer(std::move(vertex_buffer));
        m_vertex_array->SetIndexBuffer(std::move(index_buffer));
    }
    
    StaticSprite::~StaticSprite() {}
    
    const std::shared_ptr<VertexArray>& StaticSprite::GetVertexArray() const
    {
		return m_vertex_array;
    }
    
}
