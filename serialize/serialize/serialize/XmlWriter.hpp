#pragma once

namespace cc {
	
	class XmlWriter : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			string value_ = convertValue<T, string>(nValue);
			xml_attribute<char> * xmlAttribute_ =
				mXmlDocument.allocate_attribute(nName, value_.c_str());
			mXmlNode->append_attribute(xmlAttribute_);
		}
		
		template <typename T>
		void runNumbers(T& nValue, const char * nName)
		{
			string value_ = convertValue<T, string>(nValue);
			xml_node<char> * xmlNode_ =
				mXmlDocument.allocate_node(node_element, nName, value_.c_str());
			mXmlNode->append_node(xmlNode_);
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runBuffer(char *& nValue, int16_t& nLength);
		
		void runPush(const char * nName);
		void runPop(const char * nName);
		
		void pushClass(const char * nName);
		void popClass(const char * nName);
		
		void pushChild(const char * nName);
		void popChild(const char * nName);
		
		void selectStream(const char * nName);
		
		void saveFile(const char * nPath);
		
		string stringValue();
		
		bool isText();
		
		XmlWriter();
		~XmlWriter();
		
	private:
		xml_document<char> mXmlDocument;
		xml_node<char> * mXmlNode;
	};
	
}
