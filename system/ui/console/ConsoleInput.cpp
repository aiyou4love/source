#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleInput::runContext(int64_t nTick)
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		if ( consoleEngine_.isStop() ) {
			chrono::milliseconds dura_(1000);
			this_thread::sleep_for(dura_);
			return;
		}
		string command_;
		getline(cin, command_);
		
		CommandArgsPtr commandArgs_(new CommandArgs());
		commandArgs_->runParse(command_.c_str());
		
		int8_t flag_ = commandArgs_->getFlag();
		if (1 == flag_) {
			consoleEngine_.pushCommandArgs(commandArgs_);
		} else if (2 == flag_) {
			
		} else {
			
		}
	}
#endif
	
}
