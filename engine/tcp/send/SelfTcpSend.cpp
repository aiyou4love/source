#include "../../Engine.hpp"

namespace cc {
	
	void SelfTcpSend::setSession(TcpSession * nTcpSession)
	{
		mTcpSession = nTcpSession;
	}
	
	void SelfTcpSend::sendValue(ValuePtr& nValue)
	{
		if (nullptr == mTcpSession) {
			LOGE("[%s]sendValue", __METHOD__);
			return;
		}
		mTcpSession->runSend(nValue);
	}
	
	void SelfTcpSend::pushValue(ValuePtr& nValue)
	{
		Entity * entity_ = this->getEntity();
		entity_->pushValue(nValue);
	}
	
	SelfTcpSend::SelfTcpSend()
		: mTcpSession (nullptr)
	{
	}
	
	SelfTcpSend::~SelfTcpSend()
	{
		mTcpSession = nullptr;
	}
	
}
