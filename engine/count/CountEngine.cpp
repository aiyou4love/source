#include "../Engine.hpp"

namespace cc {
	
	void CountEngine::initCount(ICount * nCount, EntityPtr& nEntity, CountIndexPtr& nCountIndex)
	{
		Property * property_ = nEntity->getProperty(Eproperty::mIntArray);
		if (nullptr == property_) {
			LOGE("[%s]property", __METHOD__);
			return;
		}
		IntEntity * intEntity_ = dynamic_cast<IntEntity>(property_);
		
		int16_t int_ = nCountIndex->getInt();
		IntArray * intArray_ = intEntity_->findIntArray(int_);
		if (nullptr == intArray_) {
			LOGE("[%s]int:%d", __METHOD__, int_);
			return;
		}
		nCount->runInit(intArray_, nCountIndex);
	}
	
	void CountEngine::initCount(ICount * nCount, EntityPtr& nEntity, const char * nIndex)
	{
		int16_t entityType_ = nEntity->getEntityType();
		int32_t index_ = stringCrc(nIndex);
		
		auto it = mCountIndexs.begin();
		for ( ; it == mCountIndexs.end(); ++it ) {
			CountIndexPtr& countIndex_ = it->second;
			int32_t classify_ = countIndex_->getClassify();
			int32_t crcId_ = countIndex_->getCrcId();
			if ((classify_ != entityType_) 
				|| (crcId_ != index_) ) {
				continue;
			}
			this->initCount(nCount, nEntity, countIndex_);
			break;
		}
	}
	
	void CountEngine::initEntity(EntityPtr& nEntity)
	{
		int16_t entityType_ = nEntity->getEntityType();
		
		IntEntity * intEntity_ = new IntEntity();
		
		auto it = mIntIndexs.begin();
		for ( ; it != mIntIndexs.end(); ++it ) {
			IntIndexPtr& intIndex_ = it->second;
			int16_t classify_ = intIndex_->getClassify();
			if ( entityType_ != classify_ ) {
				continue;
			}
			intEntity_->initIntIndex(intIndex_);
		}
		PropertyPtr property_(intEntity_);
		nEntity->insertProperty(Eproperty::mIntArray, property_);
	}
	
	void CountEngine::clearEntity(int16_t nType, EntityPtr& nEntity)
	{
		Property * property_ = nEntity->getProperty(Eproperty::mIntArray);
		if (nullptr == property_) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		IntEntity * intEntity_ = dynamic_cast<IntEntity>(property_);
		intEntity_->clearIntArray(nType);
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
