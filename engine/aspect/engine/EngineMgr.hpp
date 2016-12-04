#pragma once

namespace cc {
	
	class EngineMgr : noncopyable
	{
	public:
		void registerEngine(int16_t nEngineId, IEngine * nEngine);
		IEngine * findEngine(int16_t nEngineId);
		
		void initSink(int32_t nSinkId, EntityPtr& nEntity);
		
		void runPreinit();
		void runClear();
		
		static EngineMgr& instance();
		
		EngineMgr();
		~EngineMgr();
		
	private:
		map<int16_t, IEngine *> mEngines;
		
		static EngineMgr mEngineMgr;
	};
	
}
