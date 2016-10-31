#pragma once

namespace cc {
	
	class IPlugin : noncopyable
	{
	public:
		virtual void runPlugin() = 0;
	};
	
}
