#include <mnkpch.h>
#include "sound_manager.h"

namespace mnk::audio {

	std::vector<std::shared_ptr<Sound>> SoundManager::m_sounds;

	void SoundManager::Add(std::shared_ptr<Sound> sound)
	{
		m_sounds.push_back(sound);
	}

	std::shared_ptr<Sound> SoundManager::Get(const std::string& sound_name)
	{
		for (const auto sound : m_sounds) {
			if (sound->GetName() == sound_name)
				return sound;
		}
		std::cout << "Sound (" << sound_name << ") could not find. The default sound (" << m_sounds[0]->GetName() << ") has been enabled." << std::endl;
		return m_sounds[0];
	}

}
