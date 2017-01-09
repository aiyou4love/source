#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cAccountEngine::setServerId(int32_t nServerId)
	{
		cRoleEngine& roleEngine_ = cRoleEngine::instance();
		int32_t roleId_ = roleEngine_.setServerId(nServerId);
		
		mAccount.setServerId(nServerId);
		mAccount.setRoleId(roleId_);
		mAccount.runSave();
	}
	
	const char * mRoleCreate = "roleCreate";
	int8_t cAccountEngine::roleCreate(const char * nRoleName, int16_t nRoleRace)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		const char * accountName_ = mAccount.getName();
		const char * password_ = mAccount.getPassword();
		int16_t accountType_ = mAccount.getType();
		int64_t accountId_ = mAccount.getId();
		int32_t serverId0_ = mAccount.getServerId();
		int32_t roleId0_ = mAccount.getRoleId();
		
		cRoleResult roleResult_;
		if ( !urlMgr_.runStream(roleResult_, mRoleCreate, roleResult_.streamName(),
			accountName_, password_, accountType_, operatorName_, versionNo_,
			accountId_, serverId0_, nRoleName, nRoleRace, (roleId0_ > 0)) ) {
			return 0;
		}
		int32_t errorCode_ = roleResult_.getErrorCode();
		if (1 != errorCode_) {
			return 2;
		}
		RoleItemPtr& roleItem_ = roleResult_.getRoleItem();
		int32_t serverId1_ = roleItem_->getServerId();
		int32_t roleId1_ = roleItem_->getRoleId();
		
		mAccount.setServerId(serverId1_);
		mAccount.setRoleId(roleId1_);
		mAccount.runSave();
		
		cRoleEngine& roleEngine_ = cRoleEngine::instance();
		roleEngine_.setRoleItem(roleItem_);	
		
		return 1;
	}
	
	void cAccountEngine::runCancel()
	{
		cRoleEngine& roleEngine_ = cRoleEngine::instance();
		roleEngine_.runCancel();
		
		mAccount.runClear();
		mAccount.runSave();
	}
	
	const char * mLoginUrl = "gameLogin";
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
		RoleItemPtr& roleItem_ = loginResult_.getRoleItem();
		int32_t serverId_ = serverItem_->getServerId();
		int32_t roleId_ = roleItem_->getRoleId();
		
		mAccount.setServerId(serverId_);
		mAccount.setRoleId(roleId_);
		mAccount.setPassword(nPassword);
		mAccount.setName(nName);
		mAccount.setType(nType);
		mAccount.setId(accountId_);
		mAccount.runSave();
		
		cRoleEngine& roleEngine_ = cRoleEngine::instance();
		roleEngine_.setRoleItem(roleItem_);		
		
		return 1;
	}
	
	const char * mRegisterUrl = "gameRegister";
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
	
	const char * mCheckUrl = "isRegister";
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
	
	const char * cAccountEngine::getAccountPassword()
	{
		return mAccount.getPassword();
	}
	
	const char * cAccountEngine::getAccountName()
	{
		return mAccount.getName();
	}
	
	int16_t cAccountEngine::getAccountType()
	{
		return mAccount.getType();
	}
	
	int64_t cAccountEngine::getAccountId()
	{
		return mAccount.getId();
	}
	
	int32_t cAccountEngine::getServerId()
	{
		return mAccount.getServerId();
	}
	
	int32_t cAccountEngine::getRoleId()
	{
		return mAccount.getRoleId();
	}
	
	void cAccountEngine::runLoad()
	{
		mAccount.runLoad();
	}
	
	void cAccountEngine::runSave()
	{
		mAccount.runSave();
	}
	
	void cAccountEngine::runClear()
	{
		mAccount.runClear();
	}
	
	void cAccountEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
		lifeCycle_.m_tSaveBegin.connect(bind(&cAccountEngine::runSave, this));
		lifeCycle_.m_tClearEnd.connect(bind(&cAccountEngine::runClear, this));
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
