#pragma once

namespace cc {
	
	class HandleConfig : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->template runNumberSemi<list<int16_t>, int16_t>(mIndexs, "handleIndexs");
			
			nSerialize->runNumber(mName, "contextName");
		}
		list<int16_t>& getIndexs();
		const char * getName();
		
		const char * getKey();
		
		bool isDefault();
		
		HandleConfig();
		~HandleConfig();
		
	private:
		list<int16_t> mIndexs;
		string mName;
	};
	typedef SPTR<HandleConfig> HandleConfigPtr;
	
}
