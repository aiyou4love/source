#include "../../Serialize.hpp"

namespace cc {
	
	ConfigEngine& ConfigEngine::instance()
	{
		return mConfigEngine;
	}
	
	ConfigEngine::ConfigEngine()
	{
	}
	
	ConfigEngine::~ConfigEngine()
	{
	}
	
	ConfigEngine ConfigEngine::mConfigEngine;
	
}
