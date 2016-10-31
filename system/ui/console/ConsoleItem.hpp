#pragma once

namespace cc {
	
	class ConsoleItem : noncopyable
	{
	public:
		const char * getMethod();
		const char * getName();
		int8_t getType();
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mMethod, "method");
			nSerialize->runNumber(mType, "type");
			nSerialize->runNumber(mName, "name");
			nSerialize->runNumber(mIndex, "index");
		}
		
		bool isDefault();
		int16_t getKey();
		
		ConsoleItem();
		~ConsoleItem();
		
	private:
		string mMethod;
		int8_t mType;
		string mName;
		int16_t mIndex;
	};
	typedef SPTR<ConsoleItem> ConsoleItemPtr;
	
}
