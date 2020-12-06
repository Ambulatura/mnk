#include "mnkpch.h"
#include "sound.h"

namespace mnk::audio {
	
	Sound::Sound(const std::string& sound_name, const std::string& sound_path)
		: m_name(sound_name), m_path(sound_path)
	{
		
		ma_result result = ma_decoder_init_file(m_path.c_str(), NULL, &m_decoder);
		if (result != MA_SUCCESS) {
			std::cout << "Failed to initialize sound. FILE: " << m_path << std::endl;
		}

		m_device_config = ma_device_config_init(ma_device_type_playback);
		m_device_config.playback.format   = m_decoder.outputFormat;
		m_device_config.playback.channels = m_decoder.outputChannels;
		m_device_config.sampleRate        = m_decoder.outputSampleRate;
		m_device_config.dataCallback      = DataCallback;
		m_device_config.pUserData         = &m_decoder;

		if (ma_device_init(NULL, &m_device_config, &m_device) != MA_SUCCESS) {
			std::cout << "Failed to open playback device." << std::endl;
			ma_decoder_uninit(&m_decoder);
		}
	}
	
	Sound::~Sound()
	{
		ma_device_uninit(&m_device);
		ma_decoder_uninit(&m_decoder);
	}

	void Sound::Play()
	{
		ma_decoder_seek_to_pcm_frame(&m_decoder, 0);
		ma_result result = ma_device_start(&m_device);
		if (result != MA_SUCCESS && result != MA_INVALID_OPERATION) {
			std::cout << "Failed to start playback device." << std::endl;
			ma_device_uninit(&m_device);
			ma_decoder_uninit(&m_decoder);
		}
		// ma_device_stop(&m_device);
	}

	const std::string& Sound::GetName() const
	{
		return m_name;
	}

	void Sound::DataCallback(ma_device* device, void* output, const void* input, ma_uint32 frame_count)
	{
		
		ma_decoder* decoder = (ma_decoder*)device->pUserData;
		if (decoder == NULL) {
			return;
		}

		// std::cout << "Frame count: " << frame_count << std::endl;
		
		ma_uint64 decoded_pcm_frame_count = ma_decoder_read_pcm_frames(decoder, output, frame_count);

		// std::cout << "Decoded pcm frame count: " << decoded_pcm_frame_count << std::endl;

		// if (decoded_pcm_frame_count < frame_count) {
		// 	std::cout << "Seek" << std::endl;
		// 	ma_decoder_seek_to_pcm_frame(decoder, 0);
		// }
	
	}
}
