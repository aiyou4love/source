#pragma once

namespace cc {
	
	class Plugin : public IPlugin
	{
	public:
		void runPlugin();
	};
	
	extern "C" BOOST_SYMBOL_EXPORT Plugin mPlugin;
	
}
