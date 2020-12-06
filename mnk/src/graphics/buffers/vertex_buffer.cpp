#include "mnkpch.h"
#include "vertex_buffer.h"

namespace mnk::graphics {
    
    VertexBuffer::VertexBuffer(const void* data, const uint32_t size)
    {
        glCreateBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

	VertexBuffer::VertexBuffer(const uint32_t size)
	{
		glCreateBuffers(1, &m_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}
    
    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &m_id);
    }
    
    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }
    
    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

	void VertexBuffer::SetData(const void* data, const uint32_t size)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	void VertexBuffer::SetVertexBufferLayout(const VertexBufferLayout& vertex_buffer_layout)
	{
		m_vertex_buffer_layout = vertex_buffer_layout;
	}

	const VertexBufferLayout& VertexBuffer::GetVertexBufferLayout() const
	{
		return m_vertex_buffer_layout;
	}
    
}
