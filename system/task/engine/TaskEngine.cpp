#include "../System.hpp"

namespace cc {
	
	TaskEngine TaskEngine::instance()
	{
		return mTaskEngine;
	}
	
	TaskEngine::TaskEngine()
	{
	}
	
	TaskEngine::~TaskEngine()
	{
	}
	
	TaskEngine TaskEngine::mTaskEngine;
	
}
