#include "../AutoupInc.hpp"

namespace cc {
	
	bool Startup::runStartup()
	{
		AutoupDirectory& autoupDirectory_ = AutoupDirectory::instance();
		string pluginPath_ = autoupDirectory_.pluginPath();
		if ("" == pluginPath_) return false;
		filesystem::path dllPath_(pluginPath_);
		boost::shared_ptr<IPlugin> plugin_;
		plugin_ = dll::import<IPlugin>(
			dllPath_, "mPlugin",
			dll::load_mode::append_decorations
		);
		plugin_->runPlugin();
		return true;
	}
	
}
