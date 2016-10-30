#include "../Engine.hpp"

namespace cc {
	
	int32_t Upint::getUpdateNo()
	{
		return mUpdateNo;
	}
	
	bool Upint::isDefault()
	{
		return ( (0 == mUpdateName) || (0 == mUpdateNo) );
	}
	
	int32_t Upint::getKey()
	{
		return mUpdateName;
	}
	
	Upint::Upint()
		: mUpdateName (0)
		, mUpdateNo (0)
	{
	}
	
	Upint::~Upint()
	{
		mUpdateName = 0;
		mUpdateNo = 0;
	}
	
}
