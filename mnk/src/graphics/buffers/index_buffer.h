#pragma once

#include "common.h"
#include "glad/glad.h"

namespace mnk::graphics {

	class MNK_API IndexBuffer
	{
	public:
 		IndexBuffer(const uint32_t* indices, const uint32_t count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		uint32_t GetCount() const;

	private:
		uint32_t m_id;
		uint32_t m_count;
	};

}
