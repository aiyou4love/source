#pragma once

namespace cc {
	
	class IUiEngine : noncopyable
	{
	public:
		virtual void showUi(UiName& nName) = 0;
		virtual void loadUi(UiName& nName) = 0;
		
		virtual void refreshUi(UiName& nName, OrderValue& nOrderValue) = 0;
		
		virtual void closeUi(UiName& nName) = 0;
		virtual void clearUi(int8_t nType) = 0;
	};
	
}
