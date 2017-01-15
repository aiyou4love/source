#include "../../Engine.hpp"

namespace cc {
	
	Value * PacketMgr::getPacket(ValuePtr& nValue)
	{
		return nValue.get();
	}
	
	void PacketMgr::deletePacket(ValuePtr& nValue)
	{
		int32_t index_ = nValue->getIndex();
		
		mValues.erase(index_);
	}
	
	ValuePtr& PacketMgr::createPacket()
	{
		mIndex++;
		
		ValuePtr value_(new Value());
		value_->setIndex(mIndex);
		value_->verInit();
		mValues[mIndex] = value_;
		return (mValues[mIndex]);
	}
	
	void PacketMgr::runClear()
	{
		mValues.clear();
		mIndex = 0;
	}
	
	void PacketMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&PacketMgr::runLuaApi, this));
		lifeCycle_.m_tClearEnd.connect(bind(&PacketMgr::runClear, this));
	}
	
	void PacketMgr::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<PacketMgr>("PacketMgr");
		luaEngine_.runStatic<PacketMgr>(PacketMgr::instance, "instance");
		luaEngine_.runMethod<PacketMgr>(&PacketMgr::createPacket, "createPacket");
		luaEngine_.runMethod<PacketMgr>(&PacketMgr::getPacket, "getPacket");
	}
	
	PacketMgr& PacketMgr::instance()
	{
		return mPacketMgr;
	}
	
	PacketMgr::PacketMgr()
		: mIndex (0)
	{
		mValues.clear();
	}
	
	PacketMgr::~PacketMgr()
	{
		mValues.clear();
		mIndex = 0;
	}
	
	PacketMgr PacketMgr::mPacketMgr;
	
}
