#pragma once

namespace cc {
	
	class TableReader : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			if ( mValue->IsNull() ) {
				return;
			}
			if ( !mValue->HasMember(nName) ) {
				return;
			}
			rapidjson::Value& value_ = (*mValue)[nName];
			const char * tempValue_ = value_.GetString();
			nValue = convertValue<const char *, T>(tempValue_);
		}
		
		template <typename T>
		void runNumbers(T& nValue, const char * nName)
		{
			this->runNumber(nValue, nName);
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runBuffer(char *& nValue, int16_t& nLength);
		
		void runPush(const char * nName);
		bool runChild(const char * nName);
		bool runNext(const char * nName);
		void runPop(const char * nName);
		
		void pushClass(const char * nName);
		void popClass(const char * nName);
		
		void selectStream(const char * nValue);
		
		bool loadFile(const char * nPath);
		
		void stringValue(const char * nValue);
		
		bool isText();
		
		TableReader();
		~TableReader();
		
	private:
		rapidjson::Document mDocument;
		rapidjson::Value * mValue;
		int16_t mIndex;
		int16_t mMax;
	};
	
}
