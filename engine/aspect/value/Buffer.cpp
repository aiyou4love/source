#include "../../Engine.hpp"

namespace cc {
	
	int16_t Buffer::getLength()
	{
		return mLength;
	}
	
	char * Buffer::getValue()
	{
		return mValue;
	}
	
	Buffer::Buffer()
		: mValue (nullptr)
		, mLength (0)
		, mIsNew (false)
	{
	}
	
	Buffer::Buffer(char * nValue, int16_t nLength, bool nIsNew)
		: mLength (nLength)
		, mIsNew (nIsNew)
	{
		if (nIsNew) {
			mValue = new char[nLength];
			memset(mValue, 0, nLength);
			memcpy(mValue, nValue, nLength);
		} else {
			mValue = nValue;
		}
	}
	
	Buffer::~Buffer()
	{
		if ( mIsNew && (nullptr != mValue) ) {
			delete mValue;
		}
		mValue = nullptr;
		mLength = 0;
		
		mIsNew = false;
	}
	
}
