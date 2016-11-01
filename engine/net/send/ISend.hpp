#pragma once

namespace cc {
	
	class ISend : public Property
	{
	public:
		virtual void sendValue(ValuePtr& nValue) = 0;
		virtual void pushValue(ValuePtr& nValue);
	};
	typedef SPTR<ISend> SendPtr;
	
}
