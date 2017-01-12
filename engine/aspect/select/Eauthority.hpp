#pragma once

namespace cc {
	
	struct Eauthority : noncopyable
	{
		static const int16_t mTourist = 1;
		static const int16_t mRole = 2;
		static const int16_t mPlayer = 3;
		static const int16_t mGM = 4;
		static const int16_t mDeveloper = 5;
		static const int16_t mSystem = 6;
	};
	
}
