#include "../../Serialize.hpp"

namespace cc {

	void JsonWriter::runNumber(string& nValue, const char * nName)
	{
		mValue->AddMember(RAPIDJSONSTR(nName), RAPIDJSONSTR(nValue.c_str()), RAPIDJSONALLOC);
	}
	
	void JsonWriter::runNumbers(string& nValue, const char * nName)
	{
		mValue->PushBack(RAPIDJSONSTR(nValue.c_str()), RAPIDJSONALLOC);
	}
	
	void JsonWriter::runTime(int64_t& nValue, const char * nName)
	{
		LocalTime localTime_(nValue);
		string value_ = localTime_.getStringTime();
		this->runNumber(value_, nName);
	}
	
	void JsonWriter::runTimes(int64_t& nValue, const char * nName)
	{
		LocalTime localTime_(nValue);
		string value_ = localTime_.getStringTime();
		this->runNumbers(value_, nName);
	}
	
	void JsonWriter::runBuffer(char *& nValue, int16_t& nLength)
	{
		LOGE("[%s]%d", __METHOD__, nLength);
	}
	
	void JsonWriter::runPush(const char * nName)
	{
		mValues.push(mValue);
		rapidjson::Value value_(rapidjson::kArrayType);
		mValue->AddMember(RAPIDJSONSTR(nName), value_, RAPIDJSONALLOC);
		mValue = &((*mValue)[nName]);
	}
	
	void JsonWriter::runPop(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonWriter::pushClass(const char * nName)
	{
		mValues.push(mValue);
		rapidjson::Value value_(rapidjson::kObjectType);
		mValue->AddMember(RAPIDJSONSTR(nName), value_, RAPIDJSONALLOC);
		mValue = &((*mValue)[nName]);
	}
	
	void JsonWriter::popClass(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonWriter::pushChild(const char * nName)
	{
		mValues.push(mValue);
		rapidjson::Value value_(rapidjson::kObjectType);
		mValue->PushBack(value_, RAPIDJSONALLOC);
		mValue = &((*mValue)[mValue->Size() - 1]);
	}
	
	void JsonWriter::popChild(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonWriter::selectStream(const char * nValue)
	{
		mValue = &mDocument;
	}
	
	void JsonWriter::saveFile(const char * nPath)
	{
		rapidjson::StringBuffer stringBuffer_;
		rapidjson::Writer<rapidjson::StringBuffer> writer_(stringBuffer_);
		mDocument.Accept(writer_);
		FILE * handle_ = fopen(nPath, "wb");
		if (nullptr == handle_) return;
		fputs(stringBuffer_.GetString(), handle_);
		fclose(handle_);
	}
	
	string JsonWriter::stringValue()
	{
		rapidjson::StringBuffer stringBuffer_;
		rapidjson::Writer<rapidjson::StringBuffer> writer_(stringBuffer_);
		mDocument.Accept(writer_);
		return stringBuffer_.GetString();
	}
	
	bool JsonWriter::isText()
	{
		return true;
	}
	
	JsonWriter::JsonWriter()
		: mDocument (rapidjson::kObjectType)
		, mValue (nullptr)
	{
	}
	
	JsonWriter::~JsonWriter()
	{
		mValue = nullptr;
	}
	
}
