#include "../AutoupInc.hpp"

namespace cc {
	
	size_t AutoupItem::curlFun(void * nPtr, size_t nSize, size_t nMemb, void * nStream)
	{
		FILE * handle_ = (FILE *)nStream;
		size_t write_ = fwrite(nPtr, nSize, nMemb, handle_);
		return write_;
	}
	
	bool AutoupItem::runUpdate(int16_t nTimeout)
	{
		if ( !this->runDownload(nTimeout) ) {
			return false;
		}
		if ( !this->runUncompress() ) {
			return false;
		}
		return true;
	}
	
	const char * AutoupItem::getUpdateName()
	{
		return mUpdateName.c_str();
	}
	
	int16_t AutoupItem::getUpdateNo()
	{
		return mUpdateNo;
	}
	
	bool AutoupItem::runDownload(int16_t nTimeout)
	{
		string updateUrl_ = mDownloadUrl + mPacketName;
		
		AutoupDirectory& autoupDirectory_ = AutoupDirectory::instance();
		string downloadPath_ = autoupDirectory_.downloadPath(mPacketName.c_str());
		
		mHandle = fopen(downloadPath_.c_str(), "wb");
		
		AutoupCurl autoupCurl_;
		autoupCurl_.runInit(updateUrl_.c_str());
		autoupCurl_.runCurlValue(curlFun, mHandle);
		autoupCurl_.runTimeout(nTimeout);
		if ( !autoupCurl_.runPerform() ) {
			return false;
		}
		fclose(mHandle);
		
		return true;
	}
	
	bool AutoupItem::runUncompress()
	{
		AutoupDirectory& autoupDirectory_ = AutoupDirectory::instance();
		string downloadPath_ = autoupDirectory_.downloadPath(mPacketName.c_str());
		
		string updatePath_ = autoupDirectory_.updatePath();
		if ( "so" == mUpdateName) {
			updatePath_ = autoupDirectory_.pluginDir();
		}
		
		zip_file zipFile_(downloadPath_.c_str());
		zipFile_.extractall(updatePath_.c_str());

		filesystem::path path_(downloadPath_);
		if (filesystem::exists(path_))
		{
			filesystem::remove(path_);
		}
		return true;
	}
	
	const char * AutoupItem::getKey()
	{
		return mUpdateName.c_str();
	}
	
	AutoupItem::AutoupItem()
		: mDownloadUrl("")
		, mPacketName("")
		, mUpdateName("")
		, mUpdateNo(0)
	{
	}
	
	AutoupItem::~AutoupItem()
	{		
		mDownloadUrl = "";
		mPacketName = "";
		mUpdateName = "";
		mUpdateNo = 0;
	}
	
}
