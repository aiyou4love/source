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
	
	void BufReader::runDecompress(int8_t nType)
	{
		if (EcompressType::mLz4 == nType) {
			
			lz4decompress(mBuffer, mLength, mValue, mSize);
		} else {
			zstdcompress(mBuffer, mLength, mValue, mSize);
		}
	}
	
	void BufReader::runDecrypt(int32_t nSeed)
	{
		::runDecrypt(mValue, mSize, nSeed);
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
	
	int8_t BufReader::pushBuf(char * nBuffer, int16_t nSize)
	{
		if ( mLength > 0 ) {
			if ( mCount > 0 ) {
				if ( nLength > (nSize + mCount) ) {
					memcpy( (mBuffer + mCount), nBuffer, nSize );
					mCount += nSize;
					mPos = 0;
					return 2;
				} else {
					memcpy( (mBuffer + mCount), nBuffer, (mLength - mCount) );
					mCount += mLength;
					mPos = mLength - mCount;
					return 1;
				}
			} else {
				if ( nLength > nSize ) {
					memcpy( mBuffer, nBuffer, nSize );
					mCount = nSize;
					mPos = 0;
					return 2;
				} else {
					mPos = 0;
					return 1;
				}
			}
		}
		if ( mCount > 0 ) {
			mBuffer[1] = nBuffer[0];
			mLength = (*( (int16_t *)mBuffer ));
			if ( (mLength > PACKETSIZE) || (0 == mLength) ) {
				LOGE("[%s]> PACKETSIZE or 0", __METHOD__);
				return 0;
			}
			memset(mBuffer, 0, sizeof(mBuffer));
			if ( (nSize - 1) < 1 ) {
				mCount = 0;
				mPos = 0;
				return 2;
			}
			if ( nLength > (nSize - 1) ) {
				memcpy( mBuffer, (nBuffer + 1), (nSize - 1) );
				mCount = nSize - 1;
				mPos = 0;
				return 2;
			} else {
				mPos = 1;
				mCount = 0;
				return 1;
			}
		} else {
			if ( nSize > 1 ) {
				mLength = (*( (int16_t *)nBuffer ));
				if ( mLength > PACKETSIZE ) {
					LOGE("[%s]> PACKETSIZE", __METHOD__);
					return 0;
				}
				if ( (nSize - 2) < 1 ) {
					mCount = 0;
					mPos = 0;
					return 2;
				}
				if ( nLength > (nSize - 2) ) {
					memcpy( mBuffer, (nBuffer + 2), (nSize - 2) );
					mCount = nSize - 2;
					mPos = 0;
					return 2;
				} else {
					mPos = 2;
					return 1;
				}
			} else {
				mBuffer[0] = nBuffer[0];
				mCount = 1;
				mPos = 0;
				return 2;
			}
		}
	}
	
	int8_t BufReader::nextBuf(char * nBuffer, int16_t nSize)
	{
		if ( (nSize - mPos) > 1 ) {
			mLength = (*( (int16_t *)(nBuffer + mPos) ));
			if ( mLength > PACKETSIZE ) {
				LOGE("[%s]> PACKETSIZE", __METHOD__);
				return 0;
			}
			mPos += 2;
			if ( (nSize - mPos) < 1 ) {
				mCount = 0;
				mPos = 0;
				return 2;
			}
			if ( nLength > (nSize - mPos) ) {
				memset(mBuffer, 0, sizeof(mBuffer));
				memcpy( mBuffer, (nBuffer + mPos), (nSize - mPos) );
				mCount = (nSize - mPos);
				mPos = 0;
				return 2;
			} else {
				mCount = 0;
				return 1;
			}
		} else if ( 1 == (nSize - mPos) ) {
			memset(mBuffer, 0, sizeof(mBuffer));
			mBuffer[0] = nBuffer[mPos];
			mCount = 1;
			mPos = 0;
			return 2;
		} else {
			memset(mBuffer, 0, sizeof(mBuffer));
			mCount = 0;
			mPos = 0;
			return 2;
		}
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
