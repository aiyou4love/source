#include "../../Serialize.hpp"

namespace cc {
	
	int32_t * IntArrayM::rangeInts(int16_t nBegin, int16_t nEnd)
	{
		if ( (nBegin <= 0) || (nBegin >= N) 
			|| (nEnd > N) || (nBegin >= nEnd) ) {
			LOGE("[%s]%d,%d", __METHOD__, nBegin, nEnd);
			return nullptr;
		}
		return (mValue + nBegin - 1);
	}
	
	void IntArrayM::runInit(int16_t nN)
	{
		mValue = new int32_t[nN];
		memset(mValue, 0, 4 * N);
		N = nN;
	}
	
	void IntArrayM::runDirty()
	{
		mIsDirty = true;
	}
	
	bool IntArrayM::isDirty()
	{
		return mIsDirty;
	}
	
	IntArrayM::IntArrayM()
		: mIsDirty (false)
		, mValue (nullptr)
		, N (0)
	{
	}
	
	IntArrayM::~IntArrayM()
	{
		if ( nullptr != mValue ) {
			delete [] mValue;
			mValue = nullptr;
		}
		mIsDirty = false;
		N = 0;
	}
	
}
