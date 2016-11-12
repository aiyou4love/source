#include "../../Engine.hpp"

namespace cc {
	
	CountIndexPtr& CountEngine::getCountIndex(int16_t nIndex)
	{
		auto it = mCountIndexs.find(nIndex);
		if ( it == mCountIndexs.end() ) {
			LOGE("[%s]%d", __METHOD__, nIndex);
			return 0;
		}
		return it->second;
	}
	
	int16_t CountEngine::getIntN(int16_t nIndex)
	{
		auto it = mIntIndexs.find(nIndex);
		if ( it == mIntIndexs.end() ) {
			LOGE("[%s]%d", __METHOD__, nIndex);
			return 0;
		}
		IntIndexPtr& intIndex_ = it->second;
		return intIndex_->getN();
	}
	
	void CountEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&CountEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&CountEngine::runClear, this));
	}
	
	void CountEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<CountEngine>(this, streamUrl(), streamName());
		tableEngine_.runReader<CountEngine>(this, intUrl(), intName());
	}
	
	void CountEngine::runClear()
	{
		mCountIndexs.clear();
		mIntIndexs.clear();
	}
	
	const char * CountEngine::streamName()
	{
		return "countIndex";
	}
	
	const char * CountEngine::streamUrl()
	{
		return "countIndex.json";
	}
	
	const char * CountEngine::intName()
	{
		return "intIndex";
	}
	
	const char * CountEngine::intUrl()
	{
		return "intIndex.json";
	}
	
	CountEngine& CountEngine::instance()
	{
		return mCountEngine;
	}
	
	CountEngine::CountEngine()
	{
		mCountIndexs.clear();
		mIntIndexs.clear();
	}
	
	CountEngine::~CountEngine()
	{
		mCountIndexs.clear();
		mIntIndexs.clear();
	}
	
	CountEngine CountEngine::mCountEngine;
	
}
