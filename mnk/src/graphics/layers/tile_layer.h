#pragma once

#include "common.h"
#include "layer.h"
#include "graphics/batch_renderer2d.h"
#include "transform/transform.h"

namespace mnk::graphics {

	using namespace mnk::transform;

	class MNK_API TileLayer : public Layer
	{
	public:
		TileLayer(const std::shared_ptr<Shader> shader);
		~TileLayer();
	};

}
