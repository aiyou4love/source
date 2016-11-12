#include "../../Serialize.hpp"

namespace cc {
	
	int32_t * IntArray::rangeInts(int16_t nBegin, int16_t nEnd)
	{
		if ( (nBegin <= 0) || (nBegin >= N) 
			|| (nEnd > N) || (nBegin >= nEnd) ) {
			LOGE("[%s]%d,%d", __METHOD__, nBegin, nEnd);
			return nullptr;
		}
		return (mValue + nBegin - 1);
	}
	
	void IntArray::runInit(int16_t nN)
	{
		mValue = new int32_t[nN];
		memset(mValue, 0, 4 * N);
		N = nN;
	}
	
	void IntArray::runClear()
	{
		memset(mValue, 0, 4 * N);
	}
	
	void IntArray::runDirty()
	{
		mIsDirty = true;
	}
	
	bool IntArray::isDirty()
	{
		return mIsDirty;
	}
	
	void IntArray::runSave()
	{
		mIsDirty = false;
	}
	
	IntArray::IntArray()
		: mIsDirty (false)
		, mValue (nullptr)
		, N (0)
	{
	}
	
	IntArray::~IntArray()
	{
		if ( nullptr != mValue ) {
			delete [] mValue;
			mValue = nullptr;
		}
		mIsDirty = false;
		N = 0;
	}
	
}
