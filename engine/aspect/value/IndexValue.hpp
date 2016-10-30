#pragma once

namespace cc {
	
	class IndexValue : noncopyable
	{
	public:
		int8_t getValue(int8_t nIndex);
		int8_t getCount();
		
		static void runLuaApi();
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->template runNumberSemi<vector<int8_t>, int8_t>(mIndexs, "indexs");
		}
		
		IndexValue();
		~IndexValue();
		
	private:
		vector<int8_t> mIndexs;
	};
	
}
