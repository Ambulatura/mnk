#include "mnkpch.h"
#include "vertex_buffer_layout.h"

namespace mnk::graphics {

	VertexBufferLayoutElement::VertexBufferLayoutElement(const std::string& name, const uint32_t type, const uint32_t count, const bool normalized)
		: m_name(name), m_type(type), m_count(count), m_size(GetSizeOfType(type)), m_offset(0), m_normalized(normalized) {}

	uint32_t VertexBufferLayoutElement::GetType() const
	{
		return m_type;
	}
	
	uint32_t VertexBufferLayoutElement::GetCount() const
	{
		return m_count;
	}

	uint32_t VertexBufferLayoutElement::GetOffset() const
	{
		return m_offset;
	}

	bool VertexBufferLayoutElement::GetNormalized() const
	{
		return m_normalized;
	}

	uint8_t VertexBufferLayoutElement::GetSizeOfType(const uint32_t type)
	{
		switch (type)
		{
		case GL_FLOAT:         return sizeof(float);
		case GL_UNSIGNED_INT:  return sizeof(uint32_t);
		case GL_UNSIGNED_BYTE: return sizeof(uint8_t);
		default:
			std::cout << "Type is not supported!" << std::endl;
			return 0;
		}
	}

	VertexBufferLayout::VertexBufferLayout(std::initializer_list<VertexBufferLayoutElement> elements)
		: m_elements(elements)
	{
		CalculateOffsetsAndStride();
	}

	const std::vector<VertexBufferLayoutElement>& VertexBufferLayout::GetElements() const
	{
		return m_elements;
	}

	const uint32_t VertexBufferLayout::GetStride() const
	{
		return m_stride;
	}

	std::vector<VertexBufferLayoutElement>::const_iterator VertexBufferLayout::begin() const
	{
		return m_elements.begin();
	}

	std::vector<VertexBufferLayoutElement>::const_iterator VertexBufferLayout::end() const
	{
		return m_elements.end();
	}

	std::vector<VertexBufferLayoutElement>::iterator VertexBufferLayout::begin()
	{
		return m_elements.begin();
	}

	std::vector<VertexBufferLayoutElement>::iterator VertexBufferLayout::end()
	{
		return m_elements.end();
	}

	void VertexBufferLayout::CalculateOffsetsAndStride()
	{
		m_stride = 0;
		uint32_t offset = 0;
		for (auto& element : m_elements) {
			element.m_offset = offset;
			offset += element.m_size * element.m_count;
			m_stride += element.m_size * element.m_count;
		}
	}
}
