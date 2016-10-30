#pragma once

namespace cc {
	
	class IDispatch : noncopyable
	{
	public:
		virtual void pushValue(ValuePtr& nValue) = 0;
	};
	typedef SPTR<IDispatch> DispatchPtr;
	
}
