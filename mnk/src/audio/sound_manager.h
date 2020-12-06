#pragma once

#include "common.h"
#include "sound.h"

namespace mnk::audio {

	class MNK_API SoundManager
	{
	public:
		static void Add(std::shared_ptr<Sound> sound);
		static std::shared_ptr<Sound> Get(const std::string& sound_name);
		
	private:
		static std::vector<std::shared_ptr<Sound>> m_sounds;
	};
	
}
