#include "../Engine.hpp"

namespace cc {
	
	int16_t IntIndex::getClassify()
	{
		return mClassify;
	}
	
	int16_t IntIndex::getType()
	{
		return mType;
	}
	
	int16_t IntIndex::getCount()
	{
		return mCount;
	}
	
	bool IntIndex::isDefault()
	{
		return ( (0 == mId) || (0 == mClassify)
			|| (0 == mType) || (0 == mCount));
	}
	
	int16_t IntIndex::getKey()
	{
		return mId;
	}
	
	IntIndex::IntIndex()
		: mId (0)
		, mClassify (0)
		, mType (0)
		, mCount (0)
	{
	}
	
	IntIndex::~IntIndex()
	{
		mId = 0;
		mClassify = 0;
		mType = 0;
		mCount = 0;
	}
	
}
