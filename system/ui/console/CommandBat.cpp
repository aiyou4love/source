#include "../../System.hpp"

namespace cc {
	
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
	
}
