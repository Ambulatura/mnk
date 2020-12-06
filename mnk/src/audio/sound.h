#pragma once

#include "common.h"
#include "other/miniaudio.h"

namespace mnk::audio {

	class MNK_API Sound
	{
	public:
		Sound(const std::string& sound_name, const std::string& sound_path);
		~Sound();

		void Play();
		const std::string& GetName() const;
		
	private:
		static void DataCallback(ma_device* device, void* output, const void* input, ma_uint32 frame_count);
		
	private:
		std::string m_name;
		std::string m_path;
		ma_decoder m_decoder;
		ma_device_config m_device_config;
		ma_device m_device;
	};
	
}
