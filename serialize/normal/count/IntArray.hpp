#pragma once

namespace cc {
	
	class IntArray : noncopyable
	{
	public:
		int32_t * rangeInts(int16_t nBegin, int16_t nEnd);
		
		void runInit(int16_t nType, int16_t nCount);
		
		int16_t getType();
		
		void runClear();
		
		void runDirty();
		bool isDirty();
		
		void runSave();
		
		IntArray();
		~IntArray();
		
	private:
		int32_t * mValue;
		int16_t mType;
		bool mIsDirty;
		int16_t mCount;
	};
	typedef SPTR<IntArray> IntArrayPtr;
	
}
