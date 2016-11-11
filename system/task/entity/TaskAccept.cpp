#include "../System.hpp"

namespace cc {
	
	void TaskAccept::pushTask(int16_t nTaskId, int8_t nIndex)
	{
		int32_t value_ = linkInt16(nTaskId, int16_t(nIndex));
		mInt32Count.pushInt(value_);
	}
	
	void TaskAccept::pushTask(int16_t nTaskId)
	{
		this->pushTask(nTaskId, int8_t(0));
	}
	
	void TaskAccept::popTask(int16_t nTaskId)
	{
		mInt32Count.popInt(nTaskId);
	}
	
	void TaskAccept::runInit(IntArray * nIntArray)
	{
		int16_t begin_ = 0;
		int16_t end_ = 0;
		mInt32Count.runInit(nIntArray, begin_, end_);
	}
	
	TaskAccept::TaskAccept()
	{
	}
	
	TaskAccept::~TaskAccept()
	{
	}
	
}
