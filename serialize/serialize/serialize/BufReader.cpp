#include "../../Serialize.hpp"

namespace cc {
	
	void BufReader::runNumber(string& nValue, const char * nName)
	{
		int16_t count_ = 0;
		this->runNumber<int16_t>(count_, nName);
		const char * buffer = this->getBuffer(count_);
		if (nullptr == buffer) {
			LOGE("[%s]%s", __METHOD__, nName);
			return;
		}
		nValue.assign(buffer, count_);
	}
	
	void BufReader::runNumbers(string& nValue, const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BufReader::runTime(int64_t& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BufReader::runTimes(int64_t& nValue, const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BufReader::runBuffer(char *& nValue, int16_t nLength)
	{
		const char * buffer_ = this->getBuffer(nLength);
		if (nullptr == buffer_) {
			LOGE("[%s]%d", __METHOD__, nLength);
			return;
		}
		nValue = new char[nLength];
		memset(nValue, 0, nLength);
		memcpy(nValue, buffer_, nLength);
	}
	
	void BufReader::runPush(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	bool BufReader::runChild(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
		return false;
	}
	
	bool BufReader::runNext(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
		return false;
	}
	
	void BufReader::runPop(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BufReader::pushClass(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BufReader::popClass(const char * nName)
	{
		LOGE("[%s]%s", __METHOD__, nName);
	}
	
	void BufReader::selectStream(const char * nValue)
	{
	}
	
	EpushBuf BufReader::pushBuf(char * nBuffer, int16_t nSize)
	{
		if (nSize <= 0) {
			LOGE("[%s]%d", __METHOD__, nSize);
			return EpushBuf::mError;
		}
		mBuffer = nBuffer;
		mSize = nSize;
		if (0 >= mLength) {
			this->runNumber(mLength, "");
		}
		if ( (mLength <= 0) || (mLength > (PACKETSIZE - 4)) ) {
			LOGE("[%s]%d", __METHOD__, mLength);
			return EpushBuf::mError;
		}
		if (mLength > (mSize + mLeft - 2)) {
			memcpy((mValue + mLeft), mBuffer, mSize);
			mLeft += mSize; mBuffer = nullptr; mSize = 0;
			return EpushBuf::mLength;
		}
		return EpushBuf::mFinish;
	}
	
	const char * BufReader::getBuffer(int16_t nSize)
	{
		if ( (mPos + nSize) > (mLeft + mSize) ) {
			return nullptr;
		}
		char * result_ = nullptr;
		if (mLeft <= mPos) {
			result_ = (mBuffer + mPos - mLeft);
			mPos += nSize;
			return result_;
		}
		if ((mPos + nSize) > mLeft) {
			memcpy((mValue + mPos), mBuffer, (nSize - mLeft + mPos));
		}
		result_ = (mValue + mPos);
		mPos += nSize;
		return result_;
	}
	
	void BufReader::finishBuf()
	{
		if (mPos >= (mLeft + mSize)) {
			this->runClear();
			return;
		}
		if (mPos >= mLeft) {
			memset(mValue, 0, sizeof(mValue));
			memcpy(mValue, (mBuffer + mPos - mLeft), (mSize + mLeft - mPos));
			mBuffer = nullptr; mLeft = mSize + mLeft - mPos;
			mSize = 0; mPos = 0; mLength = 0;
			return;
		}
		memcpy(mValue, (mValue + mPos), (mLeft - mPos));
		memcpy((mValue + mLeft - mPos), mBuffer, mSize);
		mBuffer = nullptr; mLeft -= mPos; mLeft += mSize;
		mPos = 0; mSize = 0; mLength = 0; 
	}
	
	void BufReader::runClear()
	{
		memset(mValue, 0, sizeof(mValue));
		mBuffer = nullptr; mLength = 0;
		mSize = 0; mLeft = 0; mPos = 0;
	}
	
	bool BufReader::isText()
	{
		return false;
	}
	
	BufReader::BufReader()
	{
	}
	
	BufReader::~BufReader()
	{
	}
	
}
