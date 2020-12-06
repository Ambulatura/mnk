#pragma once

#include "common.h"
#include <chrono>

namespace mnk::utils {

	class MNK_API Timer
	{
	public:
		Timer()
		{
			m_time = std::chrono::high_resolution_clock::now();
		}

		void Reset()
		{
			m_time = std::chrono::high_resolution_clock::now();
		}

		float Elapsed() const
		{
			auto current_time = std::chrono::high_resolution_clock::now();
			return std::chrono::duration<float>(current_time - m_time).count();
		}

		float ElapsedMilliSeconds() const
		{
			auto current_time = std::chrono::high_resolution_clock::now();
			return std::chrono::duration<float, std::milli>(current_time - m_time).count();
		}
		
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_time;
		
	};
	
}
