#include "../../Serialize.hpp"

namespace cc {
	
	int8_t IndexValue::getValue(int8_t nIndex)
	{
		if (mIndexs.size() < nIndex) {
			LOGE("[%s]index:%d", __METHOD__, nIndex);
			return 0;
		}
		return mIndexs[nIndex - 1];
	}
	
	int8_t IndexValue::getCount()
	{
		return ((int8_t)(mIndexs.size()));
	}
	
	void IndexValue::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<IndexValue>("IndexValue");
		luaEngine_.runMethod<IndexValue>(&IndexValue::getValue, "getValue");
		luaEngine_.runMethod<IndexValue>(&IndexValue::getCount, "getCount");
	}
	
	IndexValue::IndexValue()
	{
		mIndexs.clear();
	}
	
	IndexValue::~IndexValue()
	{
		mIndexs.clear();
	}
	
}
