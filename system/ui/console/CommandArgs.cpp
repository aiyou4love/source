#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * CommandArgs::getCommandArgs(int8_t nIndex)
	{
		int8_t count_ = (int8_t)(mCommandArgs.size());
		if (count_ < nIndex) {
			return "";
		}
		return mCommandArgs[nIndex - 1].c_str();
	}
	
	int8_t CommandArgs::getCommandCount()
	{
		return (int8_t)(mCommandArgs.size());
	}
	
	int32_t CommandArgs::getSelectId()
	{
		return mSelectId;
	}
	
	int8_t CommandArgs::getFlag()
	{
		return mFlag;
	}
	
	void CommandArgs::runParse(const char * nCommand)
	{
		this->runClear();
		
		vector<string> commands_;
		stringSplit<vector<string>, string>(nCommand, commands_, " ");
		auto it = commands_.begin();
		for ( ; it != commands_.end(); ) {
			string& value_ = (*it);
			if ("" == value_) {
				it = commands_.erase(it);
			} else {
				it++;
			}
		}
		if (commands_.size() < 2) {
			return;
		}
		if ("-u" == commands_[0]) {
			mFlag = 1;
		} else if ("-g" == commands_[0]) {
			mFlag = 2;
		} else {
			LOGE("[%s]%s", __METHOD__, commands_[0].c_str());
			mFlag = 0;
		}
		mSelectId = convertValue<string, int32_t>(commands_[1]);
		for ( int i = 2; i < commands_.size(); ++i ) {
			mCommandArgs.push_back(commands_[i]);
		}
	}
	
	void CommandArgs::runClear()
	{
		mCommandArgs.clear();
		mSelectId = 0;
		mFlag = 0;
	}
	
	CommandArgs::CommandArgs()
	{
		this->runClear();
	}
	
	CommandArgs::~CommandArgs()
	{
		this->runClear();
	}
#endif
	
}
