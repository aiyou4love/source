#pragma once

namespace cc {
	
	class IntArray : noncopyable
	{
	public:
		virtual int32_t * rangeInts(int16_t nBegin, int16_t nEnd) = 0;
		
		virtual void runDirty() = 0;
	};
	
}
