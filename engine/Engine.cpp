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
		
	DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
	dispatchEngine_.runPreinit();
	
	ConditionEngine& conditionEngine_ = ConditionEngine::instance();
	conditionEngine_.runPreinit();
	
	RewardEngine& rewardEngine_ = RewardEngine::instance();
	rewardEngine_.runPreinit();
	
	SelectEngine& selectEngine_ = SelectEngine::instance();
	selectEngine_.runPreinit();
	
	AspectEngine::instance();
	
}
