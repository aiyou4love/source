#pragma once

namespace cc {

#define RAPIDJSONSTR(x) rapidjson::Value::StringRefType(x)
#define RAPIDJSONALLOC mDocument.GetAllocator()

	class AutojWriter : noncopyable
	{
	public:
		template<typename T>
		void childStreamPtr(T& nValue, const char * nName)
		{
			this->pushChild(nName);
			nValue->serialize(this, 0);
			this->popChild(nName);
		}
		
		template<typename T0, typename T1>
		void runMapStreamPtrs(map<T0, T1>& nValue, const char * nNames, const char * nName)
		{
			this->runPush(nNames);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = it->second;
				this->childStreamPtr(value_, nName);
			}
			this->runPop(nNames);
		}
		
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			mValue->AddMember(RAPIDJSONSTR(nName), nValue, RAPIDJSONALLOC);
		}
		
		void runNumber(string& nValue, const char * nName);
		
		void runPush(const char * nName);
		void runPop(const char * nName);
		
		void pushChild(const char * nName);
		void popChild(const char * nName);
		
		void selectStream(const char * nValue);
		
		void saveFile(const char * nPath);
		
		AutojWriter();
		~AutojWriter();
		
	private:
		stack<rapidjson::Value *> mValues;
		rapidjson::Document mDocument;
		rapidjson::Value * mValue;
	};
	
}
