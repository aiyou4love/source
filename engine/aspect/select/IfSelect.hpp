#pragma once

namespace cc {
	
	class IfSelect : noncopyable
	{
	public:
		void runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->template runMapStreamPtrsCount<int8_t, SelectorPtr>(mSelectors, "selectors", "selector", 10);
			
			nSerialize->template runNumberSemi<vector<int16_t>, int16_t>(mIndexs, "indexs");
			nSerialize->runNumber(mIsIndex, "isIndex");
			
			nSerialize->runNumber(mIfSelectId, "ifSelectorId");
			nSerialize->runNumber(mAppType, "appType");
		}
		bool isDefault();
		int32_t getKey();
		
		IfSelect();
		~IfSelect();
		
	private:
		map<int8_t, SelectorPtr> mSelectors;
		
		vector<int16_t> mIndexs;
		bool mIsIndex;
		
		int32_t mIfSelectId;
		int16_t mAppType;
	};
	typedef SPTR<IfSelect> IfSelectPtr;
	
}
