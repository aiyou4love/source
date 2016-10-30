#pragma once

namespace cc {
	
	class PacketMgr : noncopyable
	{
	public:
		Value * getPacket(ValuePtr& nValue);
		void deletePacket(ValuePtr& nValue);
		ValuePtr& createPacket();
		
		void runPreinit();
		void runLuaApi();
		void runClear();
		
		static PacketMgr& instance();
		
		PacketMgr();
		~PacketMgr();
		
	private:
		map<int32_t, ValuePtr> mValues;
		
		int32_t mIndex;
		
		static PacketMgr mPacketMgr;
	};
	
}
