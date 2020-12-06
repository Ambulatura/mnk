#include "mnkpch.h"
#include "vertex_array.h"

namespace mnk::graphics {
    
	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &m_id);
	}
    
	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_id);
	}
    
	void VertexArray::Bind() const
	{
		glBindVertexArray(m_id);
	}
    
	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
    
	void VertexArray::AddVertexBuffer(std::unique_ptr<VertexBuffer>&& vertex_buffer)
	{
		glBindVertexArray(m_id);
		vertex_buffer->Bind();
		const auto& vertex_buffer_layout = vertex_buffer->GetVertexBufferLayout();
		for (const auto& element : vertex_buffer_layout) {
			glEnableVertexAttribArray(m_vertex_buffer_layout_index);
			glVertexAttribPointer(m_vertex_buffer_layout_index, element.GetCount(), 
				                  element.GetType(), element.GetNormalized() ? GL_TRUE : GL_FALSE, 
				                  vertex_buffer_layout.GetStride(), reinterpret_cast<const void*>(element.GetOffset()));
			m_vertex_buffer_layout_index++;
		}
		m_vertex_buffers.push_back(std::move(vertex_buffer));
	}
    
	void VertexArray::SetIndexBuffer(std::unique_ptr<IndexBuffer>&& index_buffer)
	{
		index_buffer->Bind();
		m_index_buffer = std::move(index_buffer);
	}
    
	const std::vector<std::unique_ptr<VertexBuffer>>& VertexArray::GetVertexBuffers() const
	{
		return m_vertex_buffers;
	}
    
	const std::unique_ptr<IndexBuffer>& VertexArray::GetIndexBuffer() const
	{
		return m_index_buffer;
	}
}
