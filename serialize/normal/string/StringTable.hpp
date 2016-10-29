#pragma once

namespace cc {
	
	class StringTable : noncopyable
	{
	public:
		const char * getValue();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mValue, "value");
			nSerialize->runCrc32(mId, "key");
		}
		
		bool isDefault();
		int32_t getKey();
		
		StringTable();
		~StringTable();
		
	private:
		string mValue;
		int32_t mId;
	};
	typedef SPTR<StringTable> StringTablePtr;
	
}
