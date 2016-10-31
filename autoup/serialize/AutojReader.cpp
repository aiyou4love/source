#include "../AutoupInc.hpp"

namespace cc {
	
	void AutojReader::runNumber(int16_t& nValue, const char * nName)
	{
		if ( !mValue->HasMember(nName) ) {
			return;
		}
		rapidjson::Value& value_ = (*mValue)[nName];
		nValue = (int16_t)(value_.Get<int32_t>());
	}
	
	void AutojReader::runNumber(string& nValue, const char * nName)
	{
		if ( !mValue->HasMember(nName) ) {
			return;
		}
		rapidjson::Value & value_ = (*mValue)[nName];
		nValue = value_.GetString();
	}
	
	void AutojReader::runPush(const char * nName)
	{
		mValues.push(mValue);
		mValue = &((*mValue)[nName]);
	}
	
	bool AutojReader::runChild(const char * nName)
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
	
	bool AutojReader::runNext(const char * nName)
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
	
	void AutojReader::runPop(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void AutojReader::selectStream(const char * nValue)
	{
		mValue = &mDocument;
	}
	
	bool AutojReader::loadFile(const char * nPath)
	{
		fstream stream_;
		stream_.open(nPath, ios::binary | ios::in);
		if (!stream_) {
			return false;
		}
		stream_.unsetf(ios::skipws);
        stream_.seekg(0, ios::end);
        size_t size_ = stream_.tellg();
        stream_.seekg(0);
		vector<char> data_;
        data_.resize(size_ + 1);
        stream_.read(&data_.front(), size_);
		stream_.close();
        data_[size_] = 0;
		mDocument.Parse<0>(&data_.front());
		return true;
	}
	
	void AutojReader::stringValue(const char * nValue)
	{
		mDocument.Parse<0>(nValue);
	}
	
	AutojReader::AutojReader()
		: mValue (nullptr)
		, mIndex (0)
		, mMax (0)
	{
	}
	
	AutojReader::~AutojReader()
	{
		mValue = nullptr;
		mIndex = 0;
		mMax = 0;
	}
	
}
