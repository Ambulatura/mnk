#include "mnkpch.h"
#include "mnk.h"
//#include <Windows.h>

//extern "C" {  _declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;} // for nvidia renderer

int main()
{
    using namespace mnk;
    // using namespace mnk::graphics;
    // using namespace mnk::audio;
    // using namespace mnk::math;
    // using namespace mnk::transform;

    Window window(960, 540, "mnk");
    // window.ClearColor(0.12f, 0.24f, 0.23f, 1.0f);
    window.ClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    auto shader = std::make_shared<Shader>("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    TileLayer tile_layer(shader);

    int32_t texture_ids[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shader->Bind();
    shader->SetUniformIntegerArray("u_textures", texture_ids, 10);

    std::shared_ptr<Texture> textures[] = {
		/*std::make_shared<Texture>("textures/basic.png"),
		std::make_shared<Texture>("textures/tb.png"),
		std::make_shared<Texture>("textures/tc.png"),
		std::make_shared<Texture>("textures/test.png"),
		std::make_shared<Texture>("textures/mnk.jpg"),*/
		std::make_shared<Texture>("textures/pattern18.png"),
		std::make_shared<Texture>("textures/pattern74.png"),
    };

    uint32_t count = 0;
    for (float y = 0.0f; y < 540.0f; y += 30.0f) {
		for (float x = 0.0f; x < 960.0f; x += 30.0f) {
			// if (rand() % 4 == 0)
			// 	tile_layer.Add(std::make_shared<Sprite>(Vec3(x, y, 0.0f), Vec2(29.9f, 29.9f), Vec4(0.5f, rand() % 1000 / 1000.0f, 0.1f, 1.0f)));
			// else
			tile_layer.Add(std::make_shared<Sprite>(Vec3(x, y, 0.0f), Vec2(29.9f, 29.9f), textures[0]));
			count++;
		}
    }

    std::cout << "Sprite count: " << count << std::endl;

    FontManager::Add(std::make_shared<Font>("Liberation", "fonts/liberation.ttf", 32));

    auto fps_text = std::make_shared<Text>("", 10.f, 20.f, Vec4(0.4f, 1.0f, 0.4f, 0.99f), "Liberation", 32);

    auto fps_group = std::make_shared<Group>(Transform::Translate(0.0f, window.GetHeight() - 60.0f));
    fps_group->Add(std::make_shared<Sprite>(Vec3(0.0f), Vec2(170.0f, 60.0f), Vec4(0.1f, 0.1f, 0.1f, 0.5f)));
    fps_group->Add(fps_text);

    tile_layer.Add(fps_group);

    // Sound glass("sounds/impactGlass_light_004.ogg");
    SoundManager::Add(std::make_shared<Sound>("Metal", "sounds/impactMetal_medium_000.ogg"));
    // Sound wood("sounds/impactWood_light_000.ogg");
    // Sound knife("sounds/impactGlass_light_004.ogg");
    // Sound metal2("sounds/fart.wav");

    auto block = std::make_shared<Sprite>(Vec3(0.f), Vec2(150.f, 150.f), Vec4(1.f, 0.7f, 0.8f, 1.f), textures[1]);
    tile_layer.Add(block);
    float velocity = 8.f;

	Timer timer;
	float t = 0.0f;
    double x = 0.0;
    double y = 0.0;
    uint32_t fps = 0;
    // auto previous_time =  std::chrono::high_resolution_clock::now();
    while (!window.Closed()) {

		// auto current_time = std::chrono::high_resolution_clock::now();
		fps++;

		if (timer.ElapsedMilliSeconds() > 999.0f) {
			fps_text->text = std::to_string(fps) + " fps";
			std::cout << fps << " fps" << '\r' << std::flush;
			fps = 0;
			timer.Reset();
		}

		// t += 0.001f;
		// auto renderables = tile_layer.GetRenderables();
		// for (int i = 0; i < renderables.size(); i++)
		// {
		// 	float r = sin(t) / 2.0f + 0.5f;
		// 	renderables[i]->SetColor(Vec4(r, 0.0f, 1.0f, 1.0f));
		// }
		t += 0.05f;

		float r = sin(t) / 2.0f + 0.5f;
		block->SetColor(Vec4(r, 0.7f, 0.8f, 1.0f));

		auto block_pos = block->GetPosition(); 
		if (block_pos.x + block->GetSize().x > 960 || block_pos.x < 0.0f) {
			velocity = -velocity;
			SoundManager::Get("Metal")->Play();
		}
		
		block->SetPosition(Vec3(block_pos.x + velocity, block_pos.y));
		
		window.Clear();

		window.GetCursorPosition(x, y);

		Vec4 light_position(static_cast<float>(960.0f / window.GetWidth() * x), static_cast<float>(540.0f - (540.0f / window.GetHeight() * y)));
		shader->Bind();
		shader->SetUniformFloat4f("u_light_position", light_position);

		tile_layer.Render();

		window.Update();
    }
    // knife.Play();
    return 0;
}
