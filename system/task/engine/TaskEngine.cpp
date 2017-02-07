#include "../../System.hpp"

namespace cc {
	
	void TaskEngine::acceptTask(int16_t nTaskId, EntityPtr& nEntity)
	{
		Property * property_ = nEntity->getProperty(Eproperty::mTask);
		if (nullptr == property_) {
			LOGE("[%s]property", __METHOD__);
			return;
		}
		EntityTask * entityTask_ = dynamic_cast<EntityTask *>(property_);
		entityTask_->acceptTask(nTaskId);
	}
	
	bool TaskEngine::isAccept(int16_t nTaskId, EntityPtr& nEntity)
	{
		Property * property_ = nEntity->getProperty(Eproperty::mTask);
		if (nullptr == property_) {
			LOGE("[%s]property", __METHOD__);
			return false;
		}
		EntityTask * entityTask_ = dynamic_cast<EntityTask *>(property_);
		return entityTask_->isAccept(nTaskId);
	}
	
	void TaskEngine::giveupTask(int16_t nTaskId, EntityPtr& nEntity)
	{
		Property * property_ = nEntity->getProperty(Eproperty::mTask);
		if (nullptr == property_) {
			LOGE("[%s]property", __METHOD__);
			return;
		}
		EntityTask * entityTask_ = dynamic_cast<EntityTask *>(property_);
		entityTask_->giveupTask(nTaskId);
	}
	
	void TaskEngine::finishTask(int16_t nTaskId, EntityPtr& nEntity)
	{
		auto it = mTaskConfigs.find(nTaskId);
		if ( it == mTaskConfigs.end() ) {
			LOGE("[%s]%d", __METHOD__, nTaskId);
			return;
		}
		cTaskConfigPtr& taskConfig_ = it->second;
		int16_t taskType_ = taskConfig_->getTaskType();
		int16_t taskIndex_ = taskConfig_->getTaskIndex();
		
		Property * property_ = nEntity->getProperty(Eproperty::mTask);
		if (nullptr == property_) {
			LOGE("[%s]property", __METHOD__);
			return;
		}
		EntityTask * entityTask_ = dynamic_cast<EntityTask *>(property_);
		if (EtaskType::mDaily == taskType_) {
			entityTask_->finishDaily(nTaskId);
		} else if (EtaskType::mNormal == taskType_) {
			entityTask_->finishTask(nTaskId);
		} else if (EtaskType::mSingle == taskType_) {
			entityTask_->finishSingle(taskIndex_, nTaskId);
		}
	}
	
	bool TaskEngine::isFinish(int16_t nTaskId, EntityPtr& nEntity)
	{
		auto it = mTaskConfigs.find(nTaskId);
		if ( it == mTaskConfigs.end() ) {
			LOGE("[%s]%d", __METHOD__, nTaskId);
			return false;
		}
		cTaskConfigPtr& taskConfig_ = it->second;
		int16_t taskType_ = taskConfig_->getTaskType();
		int16_t taskIndex_ = taskConfig_->getTaskIndex();
		
		Property * property_ = nEntity->getProperty(Eproperty::mTask);
		if (nullptr == property_) {
			LOGE("[%s]property", __METHOD__);
			return false;
		}
		EntityTask * entityTask_ = dynamic_cast<EntityTask *>(property_);
		if (EtaskType::mDaily == taskType_) {
			return entityTask_->isDaily(nTaskId);
		} else if (EtaskType::mNormal == taskType_) {
			return entityTask_->isFinish(nTaskId);
		} else if (EtaskType::mSingle == taskType_) {
			int16_t taskId_ = entityTask_->getSingle(taskIndex_);
			return (taskId_ == nTaskId);
		}
		return false;
	}
	
	void TaskEngine::resetTask(int16_t nTaskId, EntityPtr& nEntity)
	{
		auto it = mTaskConfigs.find(nTaskId);
		if ( it == mTaskConfigs.end() ) {
			LOGE("[%s]%d", __METHOD__, nTaskId);
			return;
		}
		cTaskConfigPtr& taskConfig_ = it->second;
		int16_t taskType_ = taskConfig_->getTaskType();
		int16_t taskIndex_ = taskConfig_->getTaskIndex();
		
		Property * property_ = nEntity->getProperty(Eproperty::mTask);
		if (nullptr == property_) {
			LOGE("[%s]property", __METHOD__);
			return;
		}
		EntityTask * entityTask_ = dynamic_cast<EntityTask *>(property_);
		if (EtaskType::mDaily == taskType_) {
			entityTask_->resetDaily(nTaskId);
		} else if (EtaskType::mNormal == taskType_) {
			entityTask_->resetTask(nTaskId);
		} else if (EtaskType::mSingle == taskType_) {
			entityTask_->resetSingle(taskIndex_);
		}
	}
	
	void TaskEngine::initEntity(EntityPtr& nEntity)
	{
		EntityTask * entityTask_ = new EntityTask();
		entityTask_->runInit(nEntity);
		
		PropertyPtr property_(entityTask_);
		nEntity->insertProperty(Eproperty::mTask, property_);
	}
	
	const char * TaskEngine::streamName()
	{
		return "taskEngine";
	}
	
	const char * TaskEngine::streamUrl()
	{
		return "taskEngine.json";
	}
	
	void TaskEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&TaskEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&TaskEngine::runClear, this));
	}
	
	void TaskEngine::runLoad()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_.runReader<TaskEngine>(this, streamUrl(), streamName());
	}
	
	void TaskEngine::runClear()
	{
		mTaskConfigs.clear();
	}
	
	TaskEngine& TaskEngine::instance()
	{
		return mTaskEngine;
	}
	
	TaskEngine::TaskEngine()
	{
	}
	
	TaskEngine::~TaskEngine()
	{
	}
	
	TaskEngine TaskEngine::mTaskEngine;
	
}
