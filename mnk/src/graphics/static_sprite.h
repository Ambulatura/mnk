#pragma once

#include "renderable2d.h"
#include "buffers/vertex_array.h"
#include "buffers/vertex_buffer.h"
#include "buffers/index_buffer.h"

namespace mnk::graphics {
    
    class StaticSprite : public Renderable2D
    {
    public:
        StaticSprite(const Vec3& position, const Vec2& size, const Vec4& color);
        ~StaticSprite();
        
        const std::shared_ptr<VertexArray>& GetVertexArray() const;
        
    private:
        std::shared_ptr<VertexArray> m_vertex_array;
    };
    
}