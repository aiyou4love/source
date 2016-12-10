#include "../../Serialize.hpp"

namespace cc {
		
	void JsonReader::runNumber(int8_t& nValue, const char * nName)
	{
		if (mValue->IsNull()) {
			return;
		}
		if ( !mValue->HasMember(nName) ) {
			return;
		}
		rapidjson::Value& value_ = (*mValue)[nName];
		nValue = static_cast<int8_t>(value_.Get<int>());
	}
	
	void JsonReader::runNumber(int16_t& nValue, const char * nName)
	{
		if (mValue->IsNull()) {
			return;
		}
		if ( !mValue->HasMember(nName) ) {
			return;
		}
		rapidjson::Value& value_ = (*mValue)[nName];
		nValue = static_cast<int16_t>(value_.Get<int>());
	}
	
	void JsonReader::runNumber(int32_t& nValue, const char * nName)
	{
		if (mValue->IsNull()) {
			return;
		}
		if ( !mValue->HasMember(nName) ) {
			return;
		}
		rapidjson::Value& value_ = (*mValue)[nName];
		nValue = static_cast<int32_t>(value_.Get<int>());
	}
	
	void JsonReader::runNumber(string& nValue, const char * nName)
	{
		if (mValue->IsNull()) {
			return;
		}
		if ( !mValue->HasMember(nName) ) {
			return;
		}
		rapidjson::Value & value_ = (*mValue)[nName];
		nValue = value_.GetString();
	}
	
	void JsonReader::runNumbers(string& nValue, const char * nName)
	{
		if (mValue->IsNull()) {
			return;
		}
		nValue = mValue->GetString();
	}
	
	void JsonReader::runTime(int64_t& nValue, const char * nName)
	{
		string value_ = "";
		this->runNumber(value_, nName);
		LocalTime localTime_(value_);
		nValue = localTime_.getNumberTime();
	}
	
	void JsonReader::runTimes(int64_t& nValue, const char * nName)
	{
		string value_ = "";
		this->runNumbers(value_, nName);
		LocalTime localTime_(value_);
		nValue = localTime_.getNumberTime();
	}
	
	void JsonReader::runBuffer(char *& nValue, int16_t nLength)
	{
		LOGE("[%s]%d", __METHOD__, nLength);
	}
	
	void JsonReader::runPush(const char * nName)
	{
		mValues.push(mValue);
		mValue = &((*mValue)[nName]);
	}
	
	bool JsonReader::runChild(const char * nName)
	{
		if (mValue->IsNull()) {
			return false;
		}
		if (mValue->Size() <= 0){
			return false;
		}
		mIndex = 0;
		mMax = mValue->Size();
		mValues.push(mValue);
		mValue = &((*mValue)[0]);
		return true;
	}
	
	bool JsonReader::runNext(const char * nName)
	{
		mIndex++;
		if ( mIndex >= mMax){
			mValue = mValues.top();
			mValues.pop();
			return false;
		}
		rapidjson::Value * value_ = mValues.top();
		mValue = &((*value_)[mIndex]);
		return true;
	}
	
	void JsonReader::runPop(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonReader::pushClass(const char * nName)
	{
		mValues.push(mValue);
		mValue = &((*mValue)[nName]);
	}
	
	void JsonReader::popClass(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonReader::selectStream(const char * nValue)
	{
		mValue = &mDocument;
	}
	
	bool JsonReader::loadFile(const char * nPath)
	{
		fstream stream_;
		stream_.open(nPath, ios::binary | ios::in);
		if (!stream_) {
			return false;
		}
		stream_.unsetf(ios::skipws);
		stream_.seekg(0, ios::end);
		size_t size_ = size_t(stream_.tellg());
		stream_.seekg(0);
		vector<char> data_;
		data_.resize(size_ + 1);
		stream_.read(&data_.front(), size_);
		stream_.close();
		data_[size_] = 0;
		mDocument.Parse<0>(&data_.front());
		return true;
	}
	
	void JsonReader::stringValue(const char * nValue)
	{
		mDocument.Parse<0>(nValue);
	}
	
	bool JsonReader::isText()
	{
		return true;
	}
	
	JsonReader::JsonReader()
		: mValue (nullptr)
		, mIndex (0)
		, mMax (0)
	{
	}
	
	JsonReader::~JsonReader()
	{
		mValue = nullptr;
		mIndex = 0;
		mMax = 0;
	}
	
}
