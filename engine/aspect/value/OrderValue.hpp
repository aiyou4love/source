#pragma once

namespace cc {
	
	class OrderValue : noncopyable
	{
	public:
		IndexValue& getIndexValue();
		ValuePtr& getValue();
		
		OrderValue(IndexValue& nIndexValue, ValuePtr& nValue);
		~OrderValue();
		
	private:
		IndexValue& mIndexValue;
		ValuePtr& mValue;
	};
	
}
