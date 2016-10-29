#include "../../Serialize.hpp"

namespace cc {
	
	void XmlReader::runNumber(string& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = 
			mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) {
			nValue = "";
			return;
		}
		nValue = xmlAttribute_->value();
	}
	
	void XmlReader::runNumbers(string& nValue, const char * nName)
	{
		nValue = mXmlNode->value();
	}
	
	void XmlReader::runTime(int64_t& nValue, const char * nName)
	{
		string value_ = "";
		this->runNumber(value_, nName);
		LocalTime localTime_(value_);
		nValue = localTime_.getNumberTime();
	}
	
	void XmlReader::runTimes(int64_t& nValue, const char * nName)
	{
		string value_ = mXmlNode->value();
		LocalTime localTime_(value_);
		nValue = localTime_.getNumberTime();
	}
	
	void XmlReader::runBuffer(char *& nValue, int16_t nLength)
	{
		LOGE("[%s]%d", __METHOD__, nLength);
	}
	
	void XmlReader::runPush(const char * nName)
	{
		mXmlNodes.push(mXmlNode);
		mXmlNode = mXmlNode->first_node(nName);
	}
	
	bool XmlReader::runChild(const char * nName)
	{
		if (nullptr == mXmlNode) {
			return false;
		}
		mXmlNode = mXmlNode->first_node(nName);
		return (nullptr != mXmlNode);
	}
	
	bool XmlReader::runNext(const char * nName)
	{
		if (nullptr == mXmlNode) {
			return false;
		}
		mXmlNode = mXmlNode->next_sibling();
		return (nullptr != mXmlNode);
	}
	
	void XmlReader::runPop(const char * nName)
	{
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}
	
	void XmlReader::pushClass(const char * nName)
	{
		mXmlNodes.push(mXmlNode);
		mXmlNode = mXmlNode->first_node(nName);
	}
	
	void XmlReader::popClass(const char * nName)
	{
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}
	
	void XmlReader::selectStream(const char * nValue)
	{
		mXmlNode = mXmlDocument.first_node();
	}
	
	void XmlReader::loadFile(const char * nPath)
	{
		mFileDoc.reset(new file<char>(nPath));
		mXmlDocument.parse<0>(mFileDoc->data());
	}
	
	void XmlReader::stringValue(const char * nValue)
	{
		mXmlDocument.parse<0>((char *)nValue);
	}
	
	bool XmlReader::isText()
	{
		return true;
	}
	
	XmlReader::XmlReader()
		: mXmlNode (nullptr)
	{
	}
	
	XmlReader::~XmlReader()
	{
		mXmlNode = nullptr;
	}
	
}
