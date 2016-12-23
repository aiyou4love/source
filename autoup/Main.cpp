#include "AutoupInc.hpp"

using namespace cc;

int main( int argc, char * argv[] )
{
#ifdef __WINDOW__
	//HWND conWnd_ = GetConsoleWindow();
	//HMENU conMenu_ = GetSystemMenu(conWnd_, 0);
	//RemoveMenu(conMenu_, 0xF060, 0x0);
#endif
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
