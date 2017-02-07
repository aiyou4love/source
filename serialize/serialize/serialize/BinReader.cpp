#include "../../Serialize.hpp"

namespace cc {
	
	void BinReader::runNumber(string& nValue, const char * nName)
	{
		int16_t count_ = 0;
		this->runNumber<int16_t>(count_, nName);
		if (0 == count_) {
			return;
		}
		nValue.resize(count_);
		mStream.read((char *)(&nValue[0]), count_);
	}
	
	void BinReader::runNumbers(string& nValue, const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BinReader::runTime(int64_t& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BinReader::runTimes(int64_t& nValue, const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BinReader::runBuffer(char *& nValue, int16_t& nLength)
	{
		this->runNumber(nLength, "length");
		if (0 == nLength) {
			return;
		}
		if (nullptr == nValue) {
			nValue = new char[nLength];
			memset(nValue, 0, nLength);
		}
		mStream.read((char *)(&nValue), nLength);
	}
	
	void BinReader::runPush(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	bool BinReader::runChild(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
		return false;
	}
	
	bool BinReader::runNext(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
		return false;
	}
	
	void BinReader::runPop(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BinReader::pushClass(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BinReader::popClass(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BinReader::selectStream(const char * nValue)
	{
	}
	
	void BinReader::openFile(const char * nPath)
	{
		mStream.open(nPath, ios::binary | ios::in);
	}
	
	void BinReader::closeFile()
	{
		mStream.close();
	}
	
	bool BinReader::isText()
	{
		return false;
	}
	
	BinReader::BinReader()
	{
	}
	
	BinReader::~BinReader()
	{
	}
	
}
