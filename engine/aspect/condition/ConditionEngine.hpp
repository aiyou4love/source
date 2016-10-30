#pragma once

namespace cc {
	
	class ConditionEngine : noncopyable
	{
	public:
		bool runCondition(int32_t nConditionId, EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runMapStreamPtrs<int32_t, ConditionPtr>(mConditions, "conditions", "condition");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		static ConditionEngine& instance();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		void runClear();
		
		ConditionEngine();
		~ConditionEngine();
		
	private:
		map<int32_t, ConditionPtr> mConditions;
		
		static ConditionEngine mConditionEngine;
	};
	
}
