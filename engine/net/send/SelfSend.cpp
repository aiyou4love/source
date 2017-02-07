#include "../../Engine.hpp"

namespace cc {
	
	void SelfSend::setSession(Session * nSession)
	{
		mSession = nSession;
	}
	
	void SelfSend::sendValue(ValuePtr& nValue)
	{
		if (nullptr == mSession) {
			LOGE("[%s]sendValue", __METHOD__);
			return;
		}
		mSession->runSend(nValue);
	}
	
	void SelfSend::pushValue(ValuePtr& nValue)
	{
		Entity * entity_ = this->getEntity();
		entity_->pushValue(nValue);
	}
	
	SelfSend::SelfSend()
		: mSession (nullptr)
	{
	}
	
	SelfSend::~SelfSend()
	{
		mSession = nullptr;
	}
	
}
