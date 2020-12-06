#pragma once

#include "common.h"

namespace mnk::utils {

	MNK_API inline const float PI = 3.14159265358979323846f;

	MNK_API inline float degree_to_radian(float degree)
	{
		return degree * PI / 180.0f;
	}

	MNK_API inline uint32_t length_of_utf8_char(const uint32_t character)
	{
		uint32_t length = 0;
		if (character) length = (character & 0x80) != 0 ? 2 : 1;
		return length;
	}

	// inline uint32_t LengthOfUtf8Text(const char* text)
	// {
	// 	uint32_t len = 0;
	// 	while (*text) len += (*text++ & 0xc0) != 0x80;
	// 	return len;
	// }

	MNK_API inline uint32_t convert_utf8_to_codepoint(const uint32_t character)
	{
		uint8_t mask = 255; // 11111111
		if ((character & mask) < 128)
			return character & mask;
		else if (((character >> 8) & mask) != 0)
			return ((character & mask) - 192) * 64 + ((character >> 8) & mask) - 128;
		return 0;
	}
}
