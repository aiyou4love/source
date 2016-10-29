#include "../../Serialize.hpp"

namespace cc {
	
	TableEngine& TableEngine::instance()
	{
		return mTableEngine;
	}
	
	TableEngine::TableEngine()
	{
	}
	
	TableEngine::~TableEngine()
	{
	}
	
	TableEngine TableEngine::mTableEngine;
	
}
