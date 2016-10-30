#pragma once

namespace cc {
	
	class DispatchEngine : noncopyable
	{
	public:
		void registerDispatch(int16_t nDispatchId, IDispatch * nDispatch);
		IDispatch * findDispatch(int16_t nDispatchId);
		
		void runPreinit();
		void runClear();
		
		static DispatchEngine& instance();
		
		DispatchEngine();
		~DispatchEngine();
		
	private:
		map<int16_t, IDispatch *> mDispatchs;
		
		static DispatchEngine mDispatchEngine;
	};
	
}
