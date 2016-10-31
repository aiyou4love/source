#include "../AutoupInc.hpp"

namespace cc {
	
	void AutojWriter::runNumber(string& nValue, const char * nName)
	{
		mValue->AddMember(RAPIDJSONSTR(nName), RAPIDJSONSTR(nValue.c_str()), RAPIDJSONALLOC);
	}
	
	void AutojWriter::runPush(const char * nName)
	{
		mValues.push(mValue);
		rapidjson::Value value_(rapidjson::kArrayType);
		mValue->AddMember(RAPIDJSONSTR(nName), value_, RAPIDJSONALLOC);
		mValue = &((*mValue)[nName]);
	}
	
	void AutojWriter::runPop(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void AutojWriter::pushChild(const char * nName)
	{
		mValues.push(mValue);
		rapidjson::Value value_(rapidjson::kObjectType);
		mValue->PushBack(value_, RAPIDJSONALLOC);
		mValue = &((*mValue)[mValue->Size() - 1]);
	}
	
	void AutojWriter::popChild(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void AutojWriter::selectStream(const char * nValue)
	{
		mValue = &mDocument;
	}
	
	void AutojWriter::saveFile(const char * nPath)
	{
		rapidjson::StringBuffer stringBuffer_;
		rapidjson::Writer<rapidjson::StringBuffer> writer_(stringBuffer_);
		mDocument.Accept(writer_);
		FILE * handle_ = fopen(nPath, "wb");
		if (nullptr == handle_) return;
		fputs(stringBuffer_.GetString(), handle_);
		fclose(handle_);
	}
	
	AutojWriter::AutojWriter()
		: mDocument (rapidjson::kObjectType)
		, mValue (nullptr)
	{
	}
	
	AutojWriter::~AutojWriter()
	{
		mValue = nullptr;
	}
	
}
