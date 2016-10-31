#include "AutoupInc.hpp"

using namespace cc;

int main( int argc, char * argv[] )
{
	AutoupDirectory& autoupDirectory_ = AutoupDirectory::instance();
	autoupDirectory_.runInit();
	{
		string logPath_ = autoupDirectory_.logPath();
		LogEx& logEx_ = LogEx::instance();
		logEx_.runInit(logPath_.c_str());
	}
	{
		AutoupEngine autoupEngine_;
		autoupEngine_.runInit();
		if (5 != autoupEngine_.runAutoup()) {
			cin.get();
			return 0;
		}
	}
	{
		Startup startup_;
		startup_.runStartup();
	}
	{
		LogEx& logEx_ = LogEx::instance();
		logEx_.runClear();
	}
	cin.get();
	return 0;
}
