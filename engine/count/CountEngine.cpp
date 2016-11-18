#include "../../Engine.hpp"

namespace cc {
	
	void CountEngine::initEntity(int16_t nClassify, EntityPtr& nEntity)
	{
		IntEntity * intEntity_ = new IntEntity();
		
		auto it = mIntIndexs.begin();
		for ( ; it != mIntIndexs.end(); ++it ) {
			IntIndexPtr& intIndex_ = it->second;
			int16_t classify_ = intIndex_->getClassify();
			if ( nClassify != classify_ ) {
				continue;
			}
			intEntity_->initIntIndex(intIndex_);
		}
		PropertyPtr property_(intEntity_);
		nEntity->insertProperty(EentityType::mIntArray, property_);
	}
	
	void CountEngine::clearEntity(int16_t nType, EntityPtr& nEntity)
	{
		PropertyPtr * property_ = nEntity->getProperty(EentityType::mIntArray);
		if (nullptr == property_) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		IntEntityPtr intEntity_ = PTR_DCST<IntEntity>(*property_);
		intEntity_->clearIntArray(nType);
	}
	
	CountIndexPtr& CountEngine::getCountIndex(int16_t nIndex)
	{
		auto it = mCountIndexs.find(nIndex);
		if ( it == mCountIndexs.end() ) {
			LOGE("[%s]%d", __METHOD__, nIndex);
			return 0;
		}
		return it->second;
	}
	
	IntIndexPtr& CountEngine::getIntIndex(int16_t nIndex)
	{
		auto it = mIntIndexs.find(nIndex);
		if ( it == mIntIndexs.end() ) {
			LOGE("[%s]%d", __METHOD__, nIndex);
			return 0;
		}
		return it->second;
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
