#pragma once

namespace cc {
	
	class IUiEngine : noncopyable
	{
	public:
		virtual void topScene(UiName& nName) = 0;
		virtual void clearScene(UiName& nName) = 0;
		virtual void refreshScene(UiName& nName) = 0;
		virtual void backScene(UiName& nName) = 0;
		
		virtual void loadUi(UiName& nName) = 0;
		
		virtual void noticeUi(UiName& nName, OrderValue& nOrderValue) = 0;
		
		virtual void closeUi(UiName& nName) = 0;
	};
	
}
