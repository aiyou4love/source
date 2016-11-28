#include "../Engine.hpp"

namespace cc {
	
	int16_t CountIndex::getBegin()
	{
		return mBegin;
	}
	
	int16_t CountIndex::getEnd()
	{
		return mEnd;
	}
	
	int16_t CountIndex::getCount()
	{
		return mCount;
	}
	
	int16_t CountIndex::getInt()
	{
		return mInt;
	}
	
	int32_t CountIndex::getCrcId()
	{
		return mCrcId;
	}
	
	int16_t CountIndex::getClassify()
	{
		return mClassify;
	}
	
	bool CountIndex::isDefault()
	{
		return ( (0 == mId) || (0 == mBegin) || (0 == mEnd)
			|| (0 == mCount) || (0 == mInt) || (0 == mCrcId)
			|| (0 == mClassify) );
	}
	
	int32_t CountIndex::getKey()
	{
		return mId;
	}
	
	CountIndex::CountIndex()
		: mBegin (0)
		, mEnd (0)
		, mId (0)
		, mCount (0)
		, mInt (0)
		, mCrcId (0)
		, mClassify (0)
	{
	}
	
	CountIndex::~CountIndex()
	{
		mBegin = 0;
		mEnd = 0;
		mCount = 0;
		mId = 0;
		mInt = 0;
		mCrcId = 0;
		mClassify = 0;
	}
	
}
