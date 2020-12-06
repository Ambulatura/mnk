#include "mnkpch.h"
#include "index_buffer.h"

namespace mnk::graphics {

	IndexBuffer::IndexBuffer(const uint32_t* indices, const uint32_t count)
		: m_count(count)
	{
		glCreateBuffers(1, &m_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indices, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(0, &m_id);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	uint32_t IndexBuffer::GetCount() const
	{
		return m_count;
	}

}
