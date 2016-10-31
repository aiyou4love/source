#pragma once

namespace cc {
	
	class AutojReader : noncopyable
	{
	public:
		template <class T>
		void instance(std::shared_ptr<T>& nValue)
		{
			nValue.reset(new T());
		}
		
		template<typename T0, typename T1>
		void runMapStreamPtrs(map<T0, T1>& nValue, const char * nNames, const char * nName)
		{
			this->runPush(nNames);
			bool result_ = this->runChild(nName);
			while ( result_ ) {
				T1 value_ = nullptr;
				instance(value_);
				value_->serialize(this, 0);
				nValue[value_->getKey()] = value_;
				result_ = this->runNext(nName);
			}
			this->runPop(nNames);
		}
		
		void runNumber(int16_t& nValue, const char * nName);
		void runNumber(string& nValue, const char * nName);
		
		void runPush(const char * nName);
		bool runChild(const char * nName);
		bool runNext(const char * nName);
		void runPop(const char * nName);
		
		void selectStream(const char * nValue);
		
		bool loadFile(const char * nPath);
		
		void stringValue(const char * nValue);
				
		AutojReader();
		~AutojReader();
		
	private:
		stack<rapidjson::Value *> mValues;
		rapidjson::Document mDocument;
		rapidjson::Value * mValue;
		int16_t mIndex;
		int16_t mMax;
	};
	
}
