#pragma once

#include "common.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "glad/glad.h"

namespace mnk::graphics {
    
	class MNK_API VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
        
		void Bind() const;
		void Unbind() const;
        
		void AddVertexBuffer(std::unique_ptr<VertexBuffer>&& vertex_buffer);
		void SetIndexBuffer(std::unique_ptr<IndexBuffer>&& index_buffer);
        
		const std::vector<std::unique_ptr<VertexBuffer>>& GetVertexBuffers() const;
		const std::unique_ptr<IndexBuffer>& GetIndexBuffer() const;
        
    private:
		uint32_t m_id;
		std::vector<std::unique_ptr<VertexBuffer>> m_vertex_buffers;
		std::unique_ptr<IndexBuffer> m_index_buffer;
		uint32_t m_vertex_buffer_layout_index = 0;
	};
    
}
