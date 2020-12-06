#pragma once

#include "common.h"
#include "glad/glad.h"
#include <initializer_list>

namespace mnk::graphics {

	class MNK_API VertexBufferLayoutElement
	{
	friend class VertexBufferLayout;
	public:
		VertexBufferLayoutElement(const std::string& name, const uint32_t type, const uint32_t count, const bool normalized);

		uint32_t GetType() const;
		uint32_t GetCount() const;
		uint32_t GetOffset() const;
		bool GetNormalized() const;

	private:
		std::string m_name;
		uint32_t m_type;
		uint32_t m_count;
		uint32_t m_size;
		uint32_t m_offset;
		bool m_normalized;

	private:
		static uint8_t GetSizeOfType(const uint32_t type);
	};


	class MNK_API VertexBufferLayout
	{
	public:
		VertexBufferLayout() = default;
		VertexBufferLayout(std::initializer_list<VertexBufferLayoutElement> elements);

		const std::vector<VertexBufferLayoutElement>& GetElements() const;
		const uint32_t GetStride() const;

		std::vector<VertexBufferLayoutElement>::const_iterator begin() const;
		std::vector<VertexBufferLayoutElement>::const_iterator end() const;
		std::vector<VertexBufferLayoutElement>::iterator begin();
		std::vector<VertexBufferLayoutElement>::iterator end();

	private:
		std::vector<VertexBufferLayoutElement> m_elements;
		uint32_t m_stride;

	private:
		void CalculateOffsetsAndStride();
	};
}









