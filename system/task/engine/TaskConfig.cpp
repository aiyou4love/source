#include "../../System.hpp"

namespace cc {
	
	int16_t TaskConfig::getTaskIndex()
	{
		return mTaskIndex;
	}
	
	int16_t TaskConfig::getTaskType()
	{
		return mFinishId;
	}
	
	int16_t TaskConfig::getTaskId()
	{
		return mTaskId;
	}
	
	bool TaskConfig::isDefault()
	{
		return ( (0 == mTaskType) || (0 == mTaskId) );
	}
	
	int16_t TaskConfig::getKey()
	{
		return mTaskId;
	}
	
	TaskConfig::TaskConfig()
		: mTaskType (0)
		, mTaskId (0)
		, mTaskIndex (0)
	{
	}
	
	TaskConfig::~TaskConfig()
	{
		mTaskType = 0;
		mTaskId = 0;
		mTaskIndex = 0;
	}
	
}
