#pragma once

namespace cc {
	
	class IUiEngine : noncopyable
	{
	public:
		virtual void showUi(const char * nName) = 0;
		virtual void loadUi(const char * nName) = 0;
		
		virtual void refreshUi(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue) = 0;
		
		virtual void closeUi(const char * nName) = 0;
		virtual void runClose() = 0;
	};
	
}
