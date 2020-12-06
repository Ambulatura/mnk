#pragma once

#include "common.h"
#include "vertex_buffer_layout.h"
#include "glad/glad.h"

namespace mnk::graphics {
    
    class MNK_API VertexBuffer
    {
    public:
        VertexBuffer(const void* data, const uint32_t size);
        VertexBuffer(const uint32_t size);
        ~VertexBuffer();
        
        void Bind() const;
        void Unbind() const;

		void SetData(const void* data, const uint32_t size);
		void SetVertexBufferLayout(const VertexBufferLayout& vertex_buffer_layout);

		const VertexBufferLayout& GetVertexBufferLayout() const;
        
    private:
        uint32_t m_id;
		VertexBufferLayout m_vertex_buffer_layout;
    };
    
}
