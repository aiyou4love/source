#pragma once

namespace cc {
	
	class CommandArgs : noncopyable
	{
	public:
		const char * getCommandArgs(int8_t nIndex);
		int8_t getCommandCount();
		int32_t getSelectId();
		int8_t getFlag();
		
		void runParse(const char * nCommand);
		void runClear();
		
		CommandArgs();
		~CommandArgs();
		
	private:
		vector<string> mCommandArgs;
		int32_t mSelectId;
		int8_t mFlag;
	};
	typedef SPTR<CommandArgs> CommandArgsPtr;
	
}
