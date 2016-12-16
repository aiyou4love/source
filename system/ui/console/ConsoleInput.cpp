#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleInput::runContext(int64_t nTick)
	{
		string command_;
		getline(cin, command_);
		
		std::system("cls");
		
		cout << "command: " << command_ << endl;
		
		CommandArgsPtr commandArgs_(new CommandArgs());
		commandArgs_->runParse(command_.c_str());
		
		int8_t flag_ = commandArgs_->getFlag();
		if (1 == flag_) {
			ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
			consoleEngine_.pushCommandArgs(commandArgs_);
		} else if (2 == flag_) {
			
		} else if (3 == flag_) {
			
		} else {
			
		}
	}
#endif
	
}
