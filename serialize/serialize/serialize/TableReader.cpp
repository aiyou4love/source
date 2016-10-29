#include "../../Serialize.hpp"

namespace cc {
	
	void TableReader::runNumber(string& nValue, const char * nName)
	{
		if ( !mValue->HasMember(nName) ) {
			return;
		}
		rapidjson::Value & value_ = (*mValue)[nName];
	#ifdef __WINDOW__
		nValue = UTF8ToGBK(value_.GetString());
	#else
		nValue = value_.GetString();
	#endif
	}
	
	void TableReader::runNumbers(string& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void TableReader::runTime(int64_t& nValue, const char * nName)
	{
		string value_ = "";
		this->runNumber(value_, nName);
		LocalTime localTime_(value_);
		nValue = localTime_.getNumberTime();
	}
	
	void TableReader::runTimes(int64_t& nValue, const char * nName)
	{
		this->runTime(nValue, nName);
	}
	
	void TableReader::runBuffer(char *& nValue, int16_t nLength)
	{
		LOGE("[%s]%d", __METHOD__, nLength);
	}
	
	void TableReader::runPush(const char * nName)
	{
	}
	
	bool TableReader::runChild(const char * nName)
	{
		return (mMax > 0);
	}
	
	bool TableReader::runNext(const char * nName)
	{
		mIndex++;
		if ( mIndex >= mMax){
			return false;
		}
		mValue = &(mDocument[mIndex]);
		return true;
	}
	
	void TableReader::runPop(const char * nName)
	{
	}
	
	void TableReader::pushClass(const char * nName)
	{
	}
	
	void TableReader::popClass(const char * nName)
	{
	}
	
	void TableReader::selectStream(const char * nValue)
	{
		if ( mDocument.Size() <= 0 ){
			return;
		}
		mIndex = 0;
		mMax = mDocument.Size();
		mValue = &(mDocument[0]);
	}
	
	bool TableReader::loadFile(const char * nPath)
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
	
	void TableReader::stringValue(const char * nValue)
	{
		mDocument.Parse<0>(nValue);
	}
	
	bool TableReader::isText()
	{
		return true;
	}
	
	TableReader::TableReader()
		: mValue (nullptr)
		, mIndex (0)
		, mMax (0)
	{
	}
	
	TableReader::~TableReader()
	{
		mValue = nullptr;
		mIndex = 0;
		mMax = 0;
	}
	
}
