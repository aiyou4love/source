#include "../../Engine.hpp"

namespace cc {
	
	void SinkEntity::initSink(EntityPtr& nEntity)
	{
		EngineMgr& engineMgr_ = EngineMgr::instance();
		
		int16_t N_ = mInt32Count.getN();
		for ( int16_t i = 1; i <= N_; ++i ) {
			int32_t value_ = mInt32Count.getInt(i);
			if (0 == value_) continue;
			engineMgr_.initSink(value_, nEntity);
		}
	}
	
	void SinkEntity::runInit(EntityPtr& nEntity)
	{
		CountEngine& countEngine_ = CountEngine::instance();
		countEngine_.initCount(&mInt32Count, nEntity, countName());
		
		this->initSink(nEntity);
	}
	
	const char * SinkEntity::countName()
	{
		return "sinkEntity";
	}
	
	SinkEntity::SinkEntity()
	{
	}
	
	SinkEntity::~SinkEntity()
	{
	}
	
}
