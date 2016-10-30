#pragma once

namespace cc {
	
	class ValueMgr : noncopyable
	{
	public:
		Value * getValue(ValuePtr& nValue);
		void deleteValue(ValuePtr& nValue);
		ValuePtr& createValue();
		
		void runPreinit();
		void runLuaApi();
		void runClear();
		
		static ValueMgr& instance();
		
		ValueMgr();
		~ValueMgr();
		
	private:
		map<int32_t, ValuePtr> mValues;
		
		int32_t mIndex;
		
		static ValueMgr mValueMgr;
	};
	
}
