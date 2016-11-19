#include "../Engine.hpp"

namespace cc {
	
	int32_t TaskConfig::getAcceptId()
	{
		return mAcceptId;
	}
	
	int32_t TaskConfig::getFinishId()
	{
		return mFinishId;
	}
	
	int16_t TaskConfig::getTaskId()
	{
		return mTaskId;
	}
	
	bool TaskConfig::isDefault()
	{
		return ( (0 == mFinishId) || (0 == mTaskId) );
	}
	
	int16_t TaskConfig::getKey()
	{
		return mTaskId;
	}
	
	TaskConfig::TaskConfig()
		: mAcceptId (0)
		, mFinishId (0)
		, mTaskId (0)
	{
	}
	
	TaskConfig::~TaskConfig()
	{
		mAcceptId = 0;
		mFinishId = 0;
		mTaskId = 0;
	}
	
}
