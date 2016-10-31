#include "../AutoupInc.hpp"

namespace cc {
	
	void AutocReader::runNumber(int16_t& nValue, const char * nName)
	{
		if (!mValue->HasMember(nName)) {
			return;
		}
		rapidjson::Value& value_ = (*mValue)[nName];
		const char * tempValue_ = value_.GetString();
        nValue = (int16_t)strtol(tempValue_, nullptr, 0);
	}
	
	void AutocReader::runNumber(string& nValue, const char * nName)
	{
		if (!mValue->HasMember(nName)) {
			return;
		}
		rapidjson::Value & value_ = (*mValue)[nName];
		nValue = value_.GetString();
	}
	
	void AutocReader::selectStream(const char * nValue)
	{
		mValue = &(mDocument[0]);
	}
	
	bool AutocReader::loadFile(const char * nPath)
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
	
	AutocReader::AutocReader()
		: mValue (nullptr)
	{
	}
	
	AutocReader::~AutocReader()
	{
		mValue = nullptr;
	}
	
}
