#include "../../Serialize.hpp"

namespace cc {
	
	int32_t * IntArray::rangeInts(int16_t nBegin, int16_t nEnd)
	{
		if ( (nBegin <= 0) || (nBegin > mCount) 
			|| (nEnd > mCount) || (nBegin > nEnd) ) {
			LOGE("[%s]%d,%d", __METHOD__, nBegin, nEnd);
			return nullptr;
		}
		return (mValue + nBegin - 1);
	}
	
	void IntArray::runInit(int16_t nType, int16_t nCount)
	{
		mValue = new int32_t[nCount];
		memset(mValue, 0, 4 * nCount);
		mCount = nCount;
		mType = nType;
	}
	
	int16_t IntArray::getType()
	{
		return mType;
	}
	
	void IntArray::runClear()
	{
		memset(mValue, 0, 4 * mCount);
		mIsDirty = true;
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
		, mCount (0)
		, mType (0)
	{
	}
	
	IntArray::~IntArray()
	{
		if ( nullptr != mValue ) {
			delete [] mValue;
			mValue = nullptr;
		}
		mIsDirty = false;
		mCount = 0;
		mType = 0;
	}
	
}
