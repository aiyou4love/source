#include "../../Engine.hpp"

namespace cc {
	
	Value * ValueMgr::getValue(ValuePtr& nValue)
	{
		return nValue.get();
	}
	
	void ValueMgr::deleteValue(ValuePtr& nValue)
	{
		int32_t index_ = nValue->getIndex();
		
		mValues.erase(index_);
	}
	
	ValuePtr& ValueMgr::createValue()
	{
		mIndex++;
		
		ValuePtr value_(new Value());
		value_->setIndex(mIndex);
		mValues[mIndex] = value_;
		return (mValues[mIndex]);
	}
	
	void ValueMgr::runClear()
	{
		mValues.clear();
		mIndex = 0;
	}
	
	void ValueMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&ValueMgr::runLuaApi, this));
		lifeCycle_.m_tClearEnd.connect(bind(&ValueMgr::runClear, this));
	}
	
	void ValueMgr::runLuaApi()
	{
		Value::runLuaApi();
		IndexValue::runLuaApi();
		
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<ValueMgr>("ValueMgr");
		luaEngine_.runStatic<ValueMgr>(ValueMgr::instance, "instance");
		luaEngine_.runMethod<ValueMgr>(&ValueMgr::deleteValue, "deleteValue");
		luaEngine_.runMethod<ValueMgr>(&ValueMgr::createValue, "createValue");
		luaEngine_.runMethod<ValueMgr>(&ValueMgr::getValue, "getValue");
	}
	
	ValueMgr& ValueMgr::instance()
	{
		return mValueMgr;
	}
	
	ValueMgr::ValueMgr()
		: mIndex (0)
	{
		mValues.clear();
	}
	
	ValueMgr::~ValueMgr()
	{
		mValues.clear();
		
		mIndex = 0;
	}
	
	ValueMgr ValueMgr::mValueMgr;
	
}
