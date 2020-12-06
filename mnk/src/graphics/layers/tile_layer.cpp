#include "mnkpch.h"
#include "tile_layer.h"

namespace mnk::graphics {

	TileLayer::TileLayer(std::shared_ptr<Shader> shader)
		: Layer(std::make_shared<BatchRenderer2D>(), shader, Transform::Orthographic(0.0f, 960.0f, 0.0f, 540.0f))
	{

	}

	TileLayer::~TileLayer()
	{
		
	}
}
