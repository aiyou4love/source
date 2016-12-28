#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * mRegisterUrl = "accountRegister";
	const char * mLoginUrl = "accountLogin";
	const char * mCheckUrl = "accountCheck";
	const char * mRoleCreate = "roleCreate";
	
	int8_t cAccountEngine::runLogin(const char * nName, const char * nPassword, int16_t nType)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cLoginResult loginResult_;
		if ( !urlMgr_.runStream(loginResult_, mLoginUrl, loginResult_.streamName(),
			nName, nPassword, operatorName_, versionNo_, nType) ) {
			return 0;
		}
		int64_t accountId_ = loginResult_.getAccountId();
		if (0 == accountId_) {
			return 2;
		}
		ServerItemPtr& serverItem_ = loginResult_.getServerItem();
		int32_t serverId_ = serverItem_->getServerId();
		RoleItemPtr& roleItem_ = loginResult_.getRoleItem();
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		account_->setRoleItem(roleItem_);
		account_->setServerId(serverId_);
		account_->setName(nName);
		account_->setPassword(nPassword);
		account_->setType(nType);
		account_->setId(accountId_);
		account_->runSave();
		return 1;
	}
	
	const char * cAccountEngine::getAccountName()
	{
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		return account_->getName();
	}
	
	int64_t cAccountEngine::getAccountId()
	{
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		return account_->getId();
	}
	
	int8_t cAccountEngine::runRegister(const char * nName, const char * nPassword)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		string value_;
		if ( !urlMgr_.runNumber(value_, mRegisterUrl, nName, nPassword) ) {
			return 0;
		}
		if ("false" == value_) {
			return 2;
		} else if ("true" == value_) {
			return 1;
		} else {
			return 3;
		}
	}
	
	int8_t cAccountEngine::isRegister(const char * nName)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		string value_;
		if ( !urlMgr_.runNumber(value_, mCheckUrl, nName) ) {
			return 0;
		}
		if ("false" == value_) {
			return 2;
		} else if ("true" == value_) {
			return 1;
		} else {
			return 3;
		}
	}
	
	void cAccountEngine::runCancel()
	{
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		account_->runClear();
		account_->runSave();
	}
	
	int32_t cAccountEngine::getRoleId()
	{
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		RoleItemPtr& roleItem_ = account_->getRoleItem();
		if (nullptr != roleItem_) {
			return roleItem_->getRoleId();
		}
		return 0;
	}
	
	void cAccountEngine::setServerId(int32_t nServerId)
	{
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		account_->setServerId(nServerId);
		account_->runSave();
	}
	
	int32_t cAccountEngine::getServerId()
	{
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		return account_->getServerId();
	}
	
	int8_t cAccountEngine::roleCreate(const char * nRoleName, int16_t nRoleRace)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		
		const char * accountName_ = account_->getName();
		const char * password_ = account_->getPassword();
		int16_t accountType_ = account_->getType();
		int64_t accountId_ = account_->getId();
		int32_t serverId_ = account_->getServerId();
		RoleItemPtr& roleItem0_ = account_->getRoleItem();
		int32_t roleId_ = roleItem0_->getRoleId();
		
		cRoleResult roleResult_;
		if ( !urlMgr_.runStream(roleResult_, mRoleCreate, roleResult_.streamName(),
			accountName_, password_, accountType_, operatorName_, versionNo_,
			accountId_, serverId_, nRoleName, nRoleRace, (roleId_ > 0)) ) {
			return 0;
		}
		int32_t errorCode_ = roleResult_.getErrorCode();
		if (1 != errorCode_) {
			return 2;
		}
		RoleItemPtr& roleItem1_ = roleResult_.getRoleItem();
		account_->setRoleItem(roleItem1_);
		account_->runSave();
		return 1;
	}
	
	EntityPtr& cAccountEngine::getAccount()
	{
		return mAccount;
	}
	
	void cAccountEngine::pushValue(ValuePtr& nValue)
	{
		mAccount->pushValue(nValue);
	}
	
	void cAccountEngine::runUpdate()
	{
		SelectEngine& selectEngine_ = SelectEngine::instance();
		
		ValuePtr value_ = mAccount->popValue();
		if (!value_) return;
		selectEngine_.runIfSelect(mAccount, value_);
	}
	
	void cAccountEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<cAccountEngine>("cAccountEngine");
		luaEngine_.runStatic<cAccountEngine>(cAccountEngine::instance, "instance");
		luaEngine_.runMethod<cAccountEngine>(&cAccountEngine::getAccount, "getAccount");
	}
	
	void cAccountEngine::runLoad()
	{
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		account_->runLoad();
	}
	
	void cAccountEngine::runInit()
	{
		AccountUpdateClone accountUpdateClone_;
		
		HandleEngine& handleEngine_ = HandleEngine::instance();
		handleEngine_.addContext(&accountUpdateClone_);
	}
	
	void cAccountEngine::runClear()
	{
		mAccount.reset();
	}
	
	void cAccountEngine::runPreinit()
	{
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		dispatchEngine_.registerDispatch(EdispatchId::mAccountId, this);
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		
		lifeCycle_.m_tRunLuaApi.connect(bind(&cAccountEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
		lifeCycle_.m_tIniting.connect(bind(&cAccountEngine::runInit, this));
		lifeCycle_.m_tClearEnd.connect(bind(&cAccountEngine::runClear, this));
		
		mAccount.reset(new cAccount());
	}
	
	cAccountEngine& cAccountEngine::instance()
	{
		return mAccountEngine;
	}
	
	cAccountEngine::cAccountEngine()
	{
	}
	
	cAccountEngine::~cAccountEngine()
	{
	}
	
	cAccountEngine cAccountEngine::mAccountEngine;
#endif
	
}
