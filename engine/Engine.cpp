#include "Engine.hpp"

using namespace cc;

void engineInit()
{
	serializeInit();
	
	HandleEngine& handleEngine_ = HandleEngine::instance();
	handleEngine_.runPreinit();
	
	UpintEngine& upintEngine_ = UpintEngine::instance();
	upintEngine_.runPreinit();
	
	ValueMgr& valueMgr_ = ValueMgr::instance();
	valueMgr_.runPreinit();
	
	PacketMgr& packetMgr_ = PacketMgr::instance();
	packetMgr_.runPreinit();
	
	
}
