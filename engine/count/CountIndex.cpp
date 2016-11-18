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
	
	bool CountIndex::isDefault()
	{
		return ( (0 == mId) || (0 == mBegin) || (0 == mEnd) );
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
	{
	}
	
	CountIndex::~CountIndex()
	{
		mBegin = 0;
		mEnd = 0;
		mCount = 0;
		mId = 0;
	}
	
}
