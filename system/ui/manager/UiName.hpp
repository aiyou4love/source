#pragma once

namespace cc {
	
	class UiName : noncopyable
	{
	public:
		const char * getName();
		int8_t getEngine();
		int8_t getScene();
		bool isTick();
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mName, "uiName");
			nSerialize->runNumber(mEngine, "uiEngine");
			nSerialize->runNumber(mScene, "uiScene");
			nSerialize->runNumber(mTick, "uiTick");
		}
		
		UiName();
		~UiName();
		
	private:
		string mName;
		int8_t mEngine;
		int8_t mScene;
		bool mTick;
	};
	
}
