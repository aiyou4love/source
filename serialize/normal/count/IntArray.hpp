#pragma once

namespace cc {
	
	class IntArray : noncopyable
	{
	public:
		int32_t * rangeInts(int16_t nBegin, int16_t nEnd);
		
		void runInit(int16_t nN);
		
		void runClear();
		
		void runDirty();
		bool isDirty();
		
		void runSave();
		
		IntArray();
		~IntArray();
		
	private:
		int32_t * mValue;
		bool mIsDirty;
		int16_t N;
	};
	typedef SPTR<IntArray> IntArrayPtr;
	
}
