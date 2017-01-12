#pragma once

namespace cc {
	
	class IfSelect : noncopyable
	{
	public:
		int32_t runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
		int32_t getIfSelectId();
		
		void setAuthority(int16_t nAuthority);
		int16_t getAuthority();
		
		bool isNet();
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->template runMapStreamPtrsCount<int8_t, SelectorPtr>(mSelectors, "selectors", "selector", 10);
			
			nSerialize->template runNumberSemi<vector<int16_t>, int16_t>(mIndexs, "indexs");
			nSerialize->runNumber(mIsNet, "isNet");
			
			nSerialize->runNumber(mAuthority, "authority");
			nSerialize->runNumber(mIfSelectId, "ifSelectorId");
		}
		bool isDefault();
		int32_t getKey();
		
		IfSelect();
		~IfSelect();
		
	private:
		map<int8_t, SelectorPtr> mSelectors;
		
		vector<int16_t> mIndexs;
		bool mIsNet;
		
		int16_t mAuthority;
		int32_t mIfSelectId;
	};
	typedef SPTR<IfSelect> IfSelectPtr;
	
}
