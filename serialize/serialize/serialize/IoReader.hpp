#pragma once

namespace cc {
	
	template <class A>
	class IoReader : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			mArchive.runNumber(nValue, nName);
		}
		
		template <typename T>
		void runNumbers(set<T>& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				T value_ = defaultValue<T>();
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					mArchive.runNumbers(value_, nName);
					nValue.insert(value_);
					value_ = defaultValue<T>();
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T value_ = defaultValue<T>();
					mArchive.runNumber(value_, nName);
					nValue.insert(value_);
				}
			}
		}
		
		template <typename T0, typename T1>
		void runNumbers(T0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				T1 value_ = defaultValue<T1>();
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					mArchive.runNumbers(value_, nName);
					nValue.push_back(value_);
					value_ = defaultValue<T1>();
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_ = defaultValue<T1>();
					mArchive.runNumber(value_, nName);
					nValue.push_back(value_);
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
				T1 value_ = defaultValue<T1>();
				for (int8_t i = 0; i < nCount; ++i) {
					this->runNumberCount(value_, nName, i);
					nValue.push_back(value_);
					value_ = defaultValue<T1>();
				}
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_ = defaultValue<T1>();
					mArchive.runNumber(value_, nName);
					nValue.push_back(value_);
				}
			}
		}
		
		template <typename T0, typename T1>
		void runNumberSemi(T0& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				string value_("");
				mArchive.runNumber(value_, nName);
				stringSplit<T0, T1>(value_.c_str(), nValue, ":");
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_ = defaultValue<T1>();
					mArchive.runNumber(value_, nName);
					nValue.push_back(value_);
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
				string value_("");
				mArchive.runNumber(value_, nName);
				nValue = stringCrc(value_.c_str());
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}
		
		template <typename T>
		void runCrc32s(T& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				string value_("");
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					mArchive.runNumbers(value_, nName);
					nValue.push_back(stringCrc(value_.c_str()));
					value_ = "";
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					int32_t value_ = 0;
					mArchive.runNumber(value_, nName);
					nValue.push_back(value_);
				}
			}
		}
		
		void runCrc32Count(int32_t& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				this->runCrc32(nValue, name_.c_str());
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}

		template <typename T>
		void runCrc32sCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				int32_t value_ = 0;
				for (int8_t i = 0; i < nCount; ++i) {
					this->runCrc32Count(value_, nName, i);
					nValue.push_back(value_);
					value_ = 0;
				}
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					int32_t value_ = 0;
					mArchive.runNumber(value_, nName);
					nValue.push_back(value_);
				}
			}
		}
		
		template <typename T>
		void runCrc32Semi(T& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				string value_("");
				this->runNumber(value_, nName);
				stringCrcSplit<T>(value_.c_str(), nValue, ":");
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					int32_t value_ = 0;
					mArchive.runNumber(value_, nName);
					nValue.push_back(value_);
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
				int64_t value_ = 0;
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					mArchive.runTimes(value_, nName);
					nValue.push_back(value_);
					value_ = 0;
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					int64_t value_ = 0;
					mArchive.runTime(value_, nName);
					nValue.push_back(value_);
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
				int64_t value_ = 0;
				for (int8_t i = 0; i < nCount; ++i) {
					this->runTimeCount(value_, nName, i);
					nValue.push_back(value_);
					value_ = 0;
				}
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					int64_t value_ = 0;
					mArchive.runTime(value_, nName);
					nValue.push_back(value_);
				}
			}
		}
		
		template <typename T>
		void runTimeSemi(T& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGE("[%s]%s", __METHOD__, nName);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					int64_t value_ = 0;
					mArchive.runTime(value_, nName);
					nValue.push_back(value_);
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
			if ( mArchive.isText() ) {
				mArchive.pushClass(nName);
				nValue->serialize(this, nName, 0);
				mArchive.popClass(nName);
			} else {
				nValue->serialize(this, nName, 0);
			}
		}
		
		template<typename T0, typename T1>
		void runStreams(T0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					T1 value_;
					value_.serialize(this, nName, 0);
					nValue.push_back(value_);
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_;
					value_.serialize(this, nName, 0);
					nValue.push_back(value_);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runStreamPtrs(T0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					value_->serialize(this, nName, 0);
					nValue.push_back(value_);
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					value_->serialize(this, nName, 0);
					nValue.push_back(value_);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreams(map<T0, T1>& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					T1 value_;
					value_.serialize(this, nName, 0);
					if (!value_.isDefault()) {
						nValue[value_.getKey()] = value_;
					}
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_;
					value_.serialize(this, nName, 0);
					if (!value_.isDefault()) {
						nValue[value_.getKey()] = value_;
					}
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreamPtrs(map<T0, T1>& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				bool result_ = mArchive.runChild(nName);
				while ( result_ ) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					value_->serialize(this, nName, 0);
					if (!value_->isDefault()) {
						nValue[value_->getKey()] = value_;
					}
					result_ = mArchive.runNext(nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					value_->serialize(this, nName, 0);
					if (!value_->isDefault()) {
						nValue[value_->getKey()] = value_;
					}
				}
			}
		}
		
		template<typename T>
		void runStreamCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.runPush(name_.c_str());
				nValue.serialize(this, nName, nCount);
				mArchive.runPop(name_.c_str());
			} else {
				nValue.serialize(this, nName, 0);
			}
		}
		
		template<typename T>
		void runStreamPtrCount(T& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(convertValue<int32_t, string>(nCount));
				mArchive.runPush(name_.c_str());
				nValue->serialize(this, nName, nCount);
				mArchive.runPop(name_.c_str());
			} else {
				nValue->serialize(this, nName, 0);
			}
		}
		
		template<typename T0, typename T1>
		void runStreamsCount(T0& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				for (int8_t i = 0; i < nCount; ++i) {
					T1 value_;
					this->runStreamCount(value_, nName, i);
					if (value_.isDefault()) {
						continue;
					}
					nValue.push_back(value_);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_;
					value_.serialize(this, nName, 0);
					nValue.push_back(value_);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runStreamPtrsCount(T0& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				for (int8_t i = 0; i < nCount; ++i) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					this->runStreamPtrCount(value_, nName, i);
					if (value_->isDefault()) {
						continue;
					}
					nValue.push_back(value_);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					value_->serialize(this, nName, 0);
					nValue.push_back(value_);
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreamsCount(map<T0, T1>& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				for (int8_t i = 0; i < nCount; ++i) {
					T1 value_;
					this->runStreamCount(value_, nName, i);
					if (value_.isDefault()) {
						continue;
					}
					nValue[value_.getKey()] = value_;
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_;
					value_.serialize(this, nName, 0);
					if (!value_.isDefault()) {
						nValue[value_.getKey()] = value_;
					}
				}
			}
		}
		
		template<typename T0, typename T1>
		void runMapStreamPtrsCount(map<T0, T1>& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				for (int8_t i = 0; i < nCount; ++i) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					this->runStreamPtrCount(value_, nName, i);
					if (value_->isDefault()) {
						continue;
					}
					nValue[value_->getKey()] = value_;
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = 0;
				mArchive.runNumber(count_, nName);
				for ( int16_t i = 0; i < count_; ++i ) {
					T1 value_ = nullptr;
					Instance::instance(value_);
					value_->serialize(this, nName, 0);
					if (!value_->isDefault()) {
						nValue[value_->getKey()] = value_;
					}
				}
			}
		}
		
		void selectStream(const char * nStreamName)
		{
			mArchive.selectStream(nStreamName);
		}
		
		IoReader(A& nArchive)
			: mArchive(nArchive)
		{
		}
		
		~IoReader()
		{
		}
		
	private:
		A& mArchive;
	};
	
}
