#include "../AutoupInc.hpp"

namespace cc {
	
	size_t AutoupEngine::curlFun(void * nPtr, size_t nSize, size_t nMemb, void * nStream)
	{
		string * value_ = (string *)nStream;
		value_->append((const char *)nPtr);
		return (nSize * nMemb);
	}
	
	int16_t AutoupEngine::runAutoup()
	{
		if ( !this->getVersionInfo() ) {
			return 1;
		}
		if (1 != mErrorCode) {
			return 2;
		}
		if ( !this->versionCheck() ) {
			return 3;
		}
		if ( !this->runUpdate() ) {
			return 4;
		}
		return 5;
	}
	
	bool AutoupEngine::getVersionInfo()
	{
		boost::format format_(mUpdateUrl);
		format_ % mOperatorName;
		format_ % mVersionNo;
		
		AutoupCurl autoupCurl_;
		autoupCurl_.runInit(format_.str().c_str());
		autoupCurl_.runCurlValue(curlFun, &mValue);
		autoupCurl_.runTimeout(mTimeout);
		bool sucess_ = false;
		for (int i = 0; i < 10; ++i) {
			if (autoupCurl_.runPerform()) {
				sucess_ = true;
				break;
			}
		}
		if (!sucess_) {
			return false;
		}
		AutojReader autojReader_;
		autojReader_.stringValue(mValue.c_str());
		autojReader_.selectStream(updateName());
		this->headSerialize(autojReader_, updateName());
		
		return true;
	}
	
	bool AutoupEngine::versionCheck()
	{
		if ( mVersionNo != mUpdateNo ) {
			return false;
		}
		return true;
	}
	
	void AutoupEngine::runSave()
	{
		AutojWriter autojWriter_;
		autojWriter_.selectStream(saveName());
		this->headSerialize(autojWriter_, saveName());
		
		AutoupDirectory& autoupDirectory_ = AutoupDirectory::instance();
		string storagePath_ = autoupDirectory_.storagePath(saveUrl());
		autojWriter_.saveFile(storagePath_.c_str());
	}
	
	bool AutoupEngine::runUpdate()
	{
		bool update_ = false;
		auto upIt = mUpdateItems.begin();
		for ( ; upIt != mUpdateItems.end(); ++upIt ) {
			string autoupName_ = upIt->first;
			AutoupItemPtr& autoupItem_ = upIt->second;
			auto saveIt = mSaveItems.find(autoupName_);
			if ( saveIt == mSaveItems.end() ) {
				AutoupSavePtr autoupSave_(new AutoupSave(autoupItem_));
				mSaveItems[autoupName_] = autoupSave_;
				update_ = true;
			} else {
				AutoupSavePtr autoupSave_ = saveIt->second;
				if ( autoupSave_->isUpdate(autoupItem_) ) {
					autoupSave_->runUpdate(autoupItem_);
					update_ = true;
				}
			}
			if ( update_ ) {
				if ( !autoupItem_->runUpdate(mTimeout) ) {
					return false;
				}
			}
		}
		if ( update_ ) {
			this->runSave();
		}
		return true;
	}
	
	const char * AutoupEngine::streamName()
	{
		return "autoupEngine";
	}
	
	const char * AutoupEngine::streamUrl()
	{
		return "autoupEngine.json";
	}
	
	const char * AutoupEngine::updateName()
	{
		return "autoupInfo";
	}

	const char * AutoupEngine::saveName()
	{
		return "autoupSave";
	}
	
	const char * AutoupEngine::saveUrl()
	{
		return "autoupSave.json";
	}
	
	void AutoupEngine::runInit()
	{
		AutoupDirectory& autoupDirectory_ = AutoupDirectory::instance();
		string assetPath_ = autoupDirectory_.configPath(streamUrl());
		AutocReader autocReader_;
		autocReader_.loadFile(assetPath_.c_str());
		autocReader_.selectStream(streamName());
		this->headSerialize(autocReader_, streamName());
		
		string storagePath_ = autoupDirectory_.storagePath(saveUrl());
		AutojReader autojReader_;
		if (autojReader_.loadFile(storagePath_.c_str())) {
			autojReader_.selectStream(saveName());
			this->headSerialize(autojReader_, saveName());
		}
	}
	
	AutoupEngine::AutoupEngine()
		: mOperatorName("")
		, mUpdateUrl("")
		, mVersionNo(0)
		, mTimeout(10)
		, mUpdateNo(0)
		, mValue ("")
	{
		mUpdateItems.clear();
		mSaveItems.clear();
	}
	
	AutoupEngine::~AutoupEngine()
	{
		mUpdateItems.clear();
		mSaveItems.clear();
		
		mOperatorName = "";
		mUpdateUrl = "";
		mVersionNo = 0;
		mTimeout = 10;
		mUpdateNo = 0;
		mValue = "";
	}
	
}
