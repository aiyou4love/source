#include "../../Engine.hpp"

namespace cc {
	
	int8_t Value::getInt8(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (1 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return 0;
		}
		if (index_ > mInt8s.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return 0;
		}
		return mInt8s[index_ - 1];
	}
	
	int16_t Value::getInt16(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (2 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return 0;
		}
		if (index_ > mInt16s.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return 0;
		}
		return mInt16s[index_ - 1];
	}
	
	int32_t Value::getInt32(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (3 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return 0;
		}
		if (index_ > mInt32s.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return 0;
		}
		return mInt32s[index_ - 1];
	}
	
	int64_t Value::getInt64(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (4 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return 0;
		}
		if (index_ > mInt64s.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return 0;
		}
		return mInt64s[index_ - 1];
	}
	
	float Value::getFloat(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (5 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return 0;
		}
		if (index_ > mFloats.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return 0;
		}
		return mFloats[index_ - 1];
	}
	
	double Value::getDouble(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (6 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return 0;
		}
		if (index_ > mDoubles.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return 0;
		}
		return mDoubles[index_ - 1];
	}
	
	const char * Value::getString(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return "";
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (7 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return "";
		}
		if (index_ > mStrings.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return "";
		}
		return mStrings[index_ - 1].c_str();
	}
	
	BufferPtr * Value::getBuffer(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return nullptr;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		number_ &= 0xFFF;
		index_ = (size_t)number_;
		if (8 != type_) {
			LOGE("[%s]type:%d", __METHOD__, type_);
			return nullptr;
		}
		if (index_ > mBuffers.size()) {
			LOGE("[%s]index:%d", __METHOD__, index_);
			return nullptr;
		}
		return (&(mBuffers[index_ - 1]));
	}
	
	intptr_t Value::getIntptr(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIntptrs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		return mIntptrs[index_ - 1];
	}
	
	void Value::pushInt8(int8_t nValue)
	{
		mInt8s.push_back(nValue);
		int16_t index_ = (1 << 12);
		index_ |= (int16_t)(mInt8s.size());
		mIndexs.push_back(index_);
	}
	
	void Value::pushInt16(int16_t nValue)
	{
		mInt16s.push_back(nValue);
		int16_t index_ = (2 << 12);
		index_ |= (int16_t)(mInt16s.size());
		mIndexs.push_back(index_);
	}
	
	void Value::setSelectId(int32_t nValue)
	{
		if ( mInt32s.size() <= 0 ) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		mInt32s[0] = nValue;
	}
	
	void Value::pushInt32(int32_t nValue)
	{
		mInt32s.push_back(nValue);
		int16_t index_ = (3 << 12);
		index_ |= (int16_t)(mInt32s.size());
		mIndexs.push_back(index_);
	}
	
	void Value::pushInt64(int64_t nValue)
	{
		mInt64s.push_back(nValue);
		int16_t index_ = (4 << 12);
		index_ |= (int16_t)(mInt64s.size());
		mIndexs.push_back(index_);
	}
	
	void Value::pushFloat(float nValue)
	{
		mFloats.push_back(nValue);
		int16_t index_ = (5 << 12);
		index_ |= (int16_t)(mFloats.size());
		mIndexs.push_back(index_);
	}
	
	void Value::pushDouble(double nValue)
	{
		mDoubles.push_back(nValue);
		int16_t index_ = (6 << 12);
		index_ |= (int16_t)(mDoubles.size());
		mIndexs.push_back(index_);
	}
	
	void Value::pushString(const char * nValue)
	{
		mStrings.push_back(nValue);
		int16_t index_ = (7 << 12);
		index_ |= (int16_t)(mStrings.size());
		mIndexs.push_back(index_);
	}
	
	void Value::pushBuffer(BufferPtr& nValue)
	{
		mBuffers.push_back(nValue);
		int16_t index_ = (int16_t)(8 << 12);
		index_ |= (int16_t)(mBuffers.size());
		mIndexs.push_back(index_);
	}
	
	void Value::pushIntptr(intptr_t nValue)
	{
		mIntptrs.push_back(nValue);
	}
	
	void Value::setIndex(int32_t nIndex)
	{
		mIndex = nIndex;
	}
	
	int32_t Value::getIndex()
	{
		return mIndex;
	}
	
	int8_t Value::verCheck(bool nHigh)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		int16_t verMax_ = workDirectory_.getVerMax();
		int16_t verMin_ = workDirectory_.getVerMin();
		if (nHigh) {
			if (mVerMax < verMax_) {
				return 0;
			}
			if (mVerMin < verMin_) {
				return 2;
			}
		} else {
			if (mVerMax > verMax_) {
				return 0;
			}
			if (mVerMin > verMin_) {
				return 2;
			}
		}
		return 1;
	}
	
	void Value::verInit()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		mVerMax = workDirectory_.getVerMax();
		mVerMin = workDirectory_.getVerMin();
	}
	
	void Value::printType(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return;
		}
		int16_t number_ = mIndexs[index_ - 1];
		int8_t type_ = (int8_t)(number_ >> 12);
		if (1 == type_) {
			LOGI("index:%d,type:int8_t", __METHOD__, nIndex);
		} else if (2 == type_) {
			LOGI("index:%d,type:int16_t", __METHOD__, nIndex);
		} else if (3 == type_) {
			LOGI("index:%d,type:int32_t", __METHOD__, nIndex);
		} else if (4 == type_) {
			LOGI("index:%d,type:int64_t", __METHOD__, nIndex);
		} else if (5 == type_) {
			LOGI("index:%d,type:float", __METHOD__, nIndex);
		} else if (6 == type_) {
			LOGI("index:%d,type:double", __METHOD__, nIndex);
		} else if (7 == type_) {
			LOGI("index:%d,type:string", __METHOD__, nIndex);
		} else if (8 == type_) {
			LOGI("index:%d,type:buffer", __METHOD__, nIndex);
		} else {
			LOGE("index:%d,type:error", __METHOD__, nIndex);
		}
	}
	
	int8_t Value::getType(int8_t nIndex)
	{
		size_t index_ = (size_t)nIndex;
		if ( (nIndex <= 0) || 
			(index_ > mIndexs.size()) ) {
			LOGE("[%s]nIndex:%d", __METHOD__, nIndex);
			return 0;
		}
		int16_t number_ = mIndexs[index_ - 1];
		return ( (int8_t)(number_ >> 12) );
	}
	
	int8_t Value::getCount()
	{
		return ((int8_t)(mIndexs.size()));
	}
	
	bool Value::checkValue(vector<int16_t>& nIndexs)
	{
		if ( mIndexs.size() != nIndexs.size() ) {
			LOGE("[%s]size:%d,%d", __METHOD__, mIndexs.size(), nIndexs.size());
			return false;
		}
		for ( size_t i = 0; i < mIndexs.size(); ++i ) {
			int16_t number_ = mIndexs[i];
			int8_t type_ = (int8_t)(number_ >> 12);
			if (type_ != nIndexs[i]) {
				LOGE("[%s]%d:%d,%d", __METHOD__, i, type_, nIndexs[i]);
				return false;
			}
		}
		return true;
	}
	
	string Value::getTextTime(int8_t nIndex)
	{
		string result_("");
		int64_t value_ = this->getInt64(nIndex);
		if (0 == value_) return result_;
		LocalTime localTime_(value_);
		return localTime_.getTextTime();
	}
		
	void Value::setSeed(int32_t nSeed)
	{
		mSeed = nSeed;
	}
	
	int32_t Value::getSeed()
	{
		return mSeed;
	}
	
	int32_t Value::getTime()
	{
		return mTime;
	}
	
	void Value::beginTime()
	{
		cServerTime& serverTime_ = cServerTime::instance();
		mTime = serverTime_.getBootTime();
	}
	
	void Value::endTime()
	{
		cServerTime& serverTime_ = cServerTime::instance();
		mTime = serverTime_.getBootTime() - mTime;
	}
	
	void Value::runClear()
	{
		mIndexs.clear();
		mInt8s.clear();
		mInt16s.clear();
		mInt32s.clear();
		mInt64s.clear();
		mFloats.clear();
		mDoubles.clear();
		mStrings.clear();
		mBuffers.clear();
		mIntptrs.clear();
		
		mVerMax = 0;
		mVerMin = 0;
		
		mSeed = 0;
		mTime = 0;
		
		mIndex = 0;
	}
	
	const char * Value::streamName()
	{
		return "value";
	}
	
	const char * Value::streamUrl()
	{
		return "value.json";
	}
	
	void Value::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<Value>("Value");
		luaEngine_.runMethod<Value>(&Value::getInt8, "getInt8");
		luaEngine_.runMethod<Value>(&Value::pushInt8, "pushInt8");
		luaEngine_.runMethod<Value>(&Value::getInt16, "getInt16");
		luaEngine_.runMethod<Value>(&Value::pushInt16, "pushInt16");
		luaEngine_.runMethod<Value>(&Value::getInt32, "getInt32");
		luaEngine_.runMethod<Value>(&Value::pushInt32, "pushInt32");
		luaEngine_.runMethod<Value>(&Value::getInt64, "getInt64");
		luaEngine_.runMethod<Value>(&Value::pushInt64, "pushInt64");
		luaEngine_.runMethod<Value>(&Value::getFloat, "getFloat");
		luaEngine_.runMethod<Value>(&Value::pushFloat, "pushFloat");
		luaEngine_.runMethod<Value>(&Value::getDouble, "getDouble");
		luaEngine_.runMethod<Value>(&Value::pushDouble, "pushDouble");
		luaEngine_.runMethod<Value>(&Value::getString, "getString");
		luaEngine_.runMethod<Value>(&Value::pushString, "pushString");
		luaEngine_.runMethod<Value>(&Value::getTextTime, "getTextTime");
		luaEngine_.runMethod<Value>(&Value::printType, "printType");
		luaEngine_.runMethod<Value>(&Value::getCount, "getCount");
		luaEngine_.runMethod<Value>(&Value::runClear, "runClear");
	}
	
	Value::Value()
	{
		this->runClear();
	}
	
	Value::~Value()
	{
		this->runClear();
	}
	
}
