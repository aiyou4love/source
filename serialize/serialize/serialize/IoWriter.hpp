#pragma once

namespace cc {
	
	template <class A>
	class IoWriter : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			mArchive.runNumber(nValue, nName);
		}
		
		template <typename T0, typename T1>
		void runNumbers(T0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					mArchive.runNumbers(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		template <typename T>
		void runNumberCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.runNumber(nValue, name_.c_str());
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}
		
		template <typename T0, typename T1>
		void runNumbersCount(T0& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1 tempValue_ = (*it);
					this->runNumberCount(tempValue_, nName, count_);
					count_++;
				}
				T1 value_ = defaultValue<T1>();
				for (int8_t i = count_; i < nCount; ++i) {
					this->runNumberCount(value_, nName, i);
				}
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		template <typename T0, typename T1>
		void runNumberSemi(T0& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				string value_ = stringCombine<T0, T1>(nValue, ":");
				mArchive.runNumber(value_, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		void runBuffer(char *& nValue, int16_t nLength)
		{
			mArchive.runBuffer(nValue, nLength);
		}
		
		void runCrc32(int32_t& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGE("[%s]%s", __METHOD__, nName);
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}
		
		template <typename T>
		void runCrc32s(T& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGE("[%s]%s,%s", __METHOD__, nNames, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int32_t& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		void runCrc32Count(int32_t& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				LOGE("[%s]%s,%d", __METHOD__, nName, nCount);
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}
		
		template <typename T>
		void runCrc32sCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				LOGE("[%s]%s,%d", __METHOD__, nName, nCount);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int32_t& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		template <typename T>
		void runCrc32Semi(T& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGE("[%s]%s", __METHOD__, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int32_t& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		void runTime(int64_t& nValue, const char * nName)
		{
			mArchive.runTime(nValue, nName);
		}
		
		template <typename T>
		void runTimes(T& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTimes(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTime(value_, nName);
				}
			}
		}
		
		void runTimeCount(int64_t& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.runTime(nValue, name_.c_str());
			} else {
				mArchive.runTime(nValue, nName);
			}
		}
		
		template <typename T>
		void runTimesCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& tempValue_ = (*it);
					this->runTimeCount(tempValue_, nName, count_);
					count_++;
				}
				int64_t value_ = 0;
				for (int8_t i = count_; i < nCount; ++i) {
					this->runTimeCount(value_, nName, i);
				}
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTime(value_, nName);
				}
			}
		}
		
		template <typename T>
		void runTimeSemi(T& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGE("[%s]%s", __METHOD__, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTime(value_, nName);
				}
			}
		}
		
		template<typename T>
		void runStream(T& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.pushClass(nName);
				nValue.serialize(this, nName, 0);
				mArchive.popClass(nName);
			} else {
				nValue.serialize(this, nName, 0);
			}
		}
		
		template<typename T>
		void runStreamPtr(T& nValue, const char * nName)
		{
			if (nullptr == nValue) {
				return;
			}
			if ( mArchive.isText() ) {
				mArchive.pushClass(nName);
				nValue->serialize(this, nName, 0);
				mArchive.popClass(nName);
			} else {
				nValue->serialize(this, nName, 0);
			}
		}
		
		template<typename T>
		void childStream(T& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.pushChild(nName);
				nValue.serialize(this, nName, 0);
				mArchive.popChild(nName);
			} else {
				nValue.serialize(this, nName, 0);
			}
		}
		
		template<typename T>
		void childStreamPtr(T& nValue, const char * nName)
		{
			if (nullptr == nValue) {
				return;
			}
			if ( mArchive.isText() ) {
				mArchive.pushChild(nName);
				nValue->serialize(this, nName, 0);
				mArchive.popChild(nName);
			} else {
				nValue->serialize(this, nName, 0);
			}
		}
		
		template<typename T0, typename T1>
		void runStreams(T0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					this->childStream(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					value_.serialize(this, nName, 0);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runStreamPtrs(T0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					this->childStreamPtr(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					value_->serialize(this, nName, 0);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreams(map<T0, T1>& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					this->childStream(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					value_.serialize(this, nName, 0);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreamPtrs(map<T0, T1>& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					this->childStreamPtr(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					value_->serialize(this, nName, 0);
				}
			}
		}
		
		template<typename T>
		void runStreamCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.pushClass(name_.c_str());
				nValue.serialize(this, nName, nCount);
				mArchive.popClass(name_.c_str());
			} else {
				nValue.serialize(this, nName, 0);
			}
		}
		
		template<typename T>
		void runStreamPtrCount(T& nValue, const char * nName, int8_t nCount)
		{
			if (nullptr == nValue) {
				return;
			}
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.pushClass(name_.c_str());
				nValue->serialize(this, nName, nCount);
				mArchive.popClass(name_.c_str());
			} else {
				nValue->serialize(this, nName, 0);
			}
		}
		
		template<typename T>
		void childStreamCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.pushChild(name_.c_str());
				nValue.serialize(this, nName, nCount);
				mArchive.popChild(name_.c_str());
			} else {
				nValue.serialize(this, nName, 0);
			}
		}
		
		template<typename T>
		void childStreamPtrCount(T& nValue, const char * nName, int8_t nCount)
		{
			if (nullptr == nValue) {
				return;
			}
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.pushChild(name_.c_str());
				nValue->serialize(this, nName, nCount);
				mArchive.popChild(name_.c_str());
			} else {
				nValue->serialize(this, nName, 0);
			}
		}
		template<typename T0, typename T1>
		void runStreamsCount(T0& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					this->childStreamCount(value_, nName, count_);
					count_++;
				}
				 T1 value_;
				for (int8_t i = count_; i < nCount; ++i) {
					this->childStreamCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					value_.serialize(this, nName, 0);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runStreamPtrsCount(T0& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T0& value_ = (*it);
					this->childStreamPtrCount(value_, nName, count_);
					count_++;
				}
				T1 value_ = nullptr;
				Instance::instance(value_);
				for (int8_t i = count_; i < nCount; ++i) {
					this->childStreamPtrCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = (*it);
					value_->serialize(this, nName, 0);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreamsCount(map<T0, T1>& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					this->childStreamCount(value_, nName, count_);
					count_++;
				}
				 T1 value_;
				for (int8_t i = count_; i < nCount; ++i) {
					this->childStreamCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					value_.serialize(this, nName, 0);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreamPtrsCount(map<T0, T1>& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					this->childStreamPtrCount(value_, nName, count_);
					count_++;
				}
				T1 value_ = nullptr;
				Instance::instance(value_);
				for (int8_t i = count_; i < nCount; ++i) {
					this->childStreamPtrCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					T1& value_ = it->second;
					value_->serialize(this, nName, 0);
				}
			}
		}
		
		void selectStream(const char * nStreamName)
		{
			mArchive.selectStream(nStreamName);
		}
		
		IoWriter(A& nArchive)
			: mArchive(nArchive)
		{
		}
		
		~IoWriter()
		{
		}
		
	private:
		A& mArchive;
	};
	
}
