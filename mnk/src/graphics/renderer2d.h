#pragma once

#include "common.h"
#include "glad/glad.h"
#include "math/mat4.h"
#include "math/vec4.h"
#include <vector>

namespace mnk::graphics {

	class Renderable2D;
	class Font;

    using mnk::math::Mat4;
	using mnk::math::Vec4;

    class MNK_API Renderer2D
    {
    public:
        virtual ~Renderer2D() {}

		virtual void Start() = 0;
        virtual void Submit(const std::shared_ptr<Renderable2D> renderable) = 0;
		virtual void End() = 0;

		virtual void SubmitText(const std::string& text, float offset_x, float offset_y, const Vec4& color, const std::shared_ptr<Font> font) {}

		void Push(const Mat4& mat4, bool override_previous = false)
		{
			if (override_previous)
				m_transformation_stack.push_back(mat4);
			else
				m_transformation_stack.push_back(m_transformation_stack.back() * mat4);
			m_transformation_back = &m_transformation_stack.back();
		}

		void Pop()
		{
			if (m_transformation_stack.size() > 1)
				m_transformation_stack.pop_back();

			m_transformation_back = &m_transformation_stack.back();
		}
    protected:
		Renderer2D()
		{
			m_transformation_stack.push_back(Mat4::Identity());
			m_transformation_back = &m_transformation_stack.back();
		}

		virtual void SubmitGlyph(const uint32_t character, float offset_x, float offset_y, const Vec4& color) {}

		virtual void Flush() = 0;
		
	protected:
		std::vector<Mat4> m_transformation_stack;
		const Mat4* m_transformation_back;
    };
}
