#pragma once

namespace cc {
	
	class AutocReader : noncopyable
	{
	public:
		template<typename T0, typename T1>
		void runMapStreamPtrs(map<T0, T1>& nValue, const char * nNames, const char * nName)
		{
		}
		
		void runNumber(int16_t& nValue, const char * nName);
		void runNumber(string& nValue, const char * nName);
		
		void selectStream(const char * nValue);
		bool loadFile(const char * nPath);
		
		AutocReader();
		~AutocReader();
		
	private:
		rapidjson::Document mDocument;
		rapidjson::Value * mValue;
	};
	
}
