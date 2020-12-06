#pragma once

#include "renderer2d.h"
#include "renderable2d.h"
#include "static_sprite.h"
#include "glad/glad.h"

namespace mnk::graphics {
    
    class StaticRenderer2D : public Renderer2D
    {
	public:
        StaticRenderer2D();
        ~StaticRenderer2D();
        
		void Start() override;
        void Submit(const std::shared_ptr<Renderable2D> renderable) override;
		void End() override;
    private:
        std::deque<std::shared_ptr<StaticSprite>> m_renderables;
		bool started;
	private:
		void Flush() override;
    };
    
}
