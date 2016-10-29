#pragma once

namespace cc {

#define RAPIDJSONSTR(x) rapidjson::Value::StringRefType(x)
#define RAPIDJSONALLOC mDocument.GetAllocator()

	class JsonWriter : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			mValue->AddMember(RAPIDJSONSTR(nName), nValue, RAPIDJSONALLOC);
		}
		
		template <typename T>
		void runNumbers(T& nValue, const char * nName)
		{
			mValue->PushBack(nValue, RAPIDJSONALLOC);
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runBuffer(char *& nValue, int16_t nLength);
		
		void runPush(const char * nName);
		void runPop(const char * nName);
		
		void pushClass(const char * nName);
		void popClass(const char * nName);
		
		void pushChild(const char * nName);
		void popChild(const char * nName);
		
		void selectStream(const char * nValue);
		
		void saveFile(const char * nPath);
		
		string stringValue();
		
		bool isText();
		
		JsonWriter();
		~JsonWriter();
		
	private:
		stack<rapidjson::Value *> mValues;
		rapidjson::Document mDocument;
		rapidjson::Value * mValue;
	};
	
}
