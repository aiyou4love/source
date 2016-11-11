#pragma once

namespace cc {
	
	class IntArrayM : public IntArray
	{
	public:
		int32_t * rangeInts(int16_t nBegin, int16_t nEnd);
		
		void runInit(int16_t nN);
		
		void runDirty();
		bool isDirty();
		
		IntArrayM();
		~IntArrayM();
		
	private:
		int32_t * mValue;
		bool mIsDirty;
		int16_t N;
	};
	typedef SPTR<IntArrayM> IntArrayMPtr;
	
}
