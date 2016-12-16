#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	list<string>& CommandBat::getCommands()
	{
		return mCommands;
	}
	
	const char * CommandBat::streamName()
	{
		return "commandBat";
	}
	
	CommandBat::CommandBat()
	{
		mCommands.clear();
	}
	
	CommandBat::~CommandBat()
	{
		mCommands.clear();
	}
#endif
	
}
