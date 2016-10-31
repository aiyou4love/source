#include "../../Engine.hpp"

namespace cc {
	
	size_t CurlFile::curlFun(void * nPtr, size_t nSize, size_t nMemb, void * nStream)
	{
		FILE * handle_ = (FILE *)nStream;
		size_t write_ = ::fwrite(nPtr, nSize, nMemb, handle_);
		return write_;
	}
	
	CurlFun_t CurlFile::getCurlFun()
	{
		return curlFun;
	}
	
	void * CurlFile::getCurlValue()
	{
		return mHandle;
	}
	
	void CurlFile::runOpen(const char * nPath)
	{
		mHandle = ::fopen(nPath, "wb");
		mPathName = nPath;
	}
	
	void CurlFile::runClose()
	{
		::fclose(mHandle);
	}
	
	const char * CurlFile::getValue()
	{
		return mPathName.c_str();
	}
	
	CurlFile::CurlFile(const char * nPath)
	{
		this->runOpen(nPath);
	}
	
	CurlFile::CurlFile()
		: mPathName (nullptr)
		, mHandle (nullptr)
	{
	}
	
	CurlFile::~CurlFile()
	{
		mPathName = nullptr;
		mHandle = nullptr;
	}
	
}
