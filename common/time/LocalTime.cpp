#include "../Serialize.hpp"

namespace cc {
	
	void LocalTime::adjustWeekDay(int8_t nWeeks, int8_t nWeek, int8_t nHour, int8_t nMin, int8_t nSec)
	{
		int8_t days_ = nWeek - mWeek;
		if (nWeek > mWeek) {
			days_ -= 7;
		}
		int64_t numberTime_ = getNumberTime();
		numberTime_ += (nWeeks * 604800);
		numberTime_ += (days_ * 86400);
		this->adjustTime(numberTime_, nHour, nMin, nSec);
	}
	
	void LocalTime::adjustWeekDay(int8_t nWeeks, int8_t nWeek)
	{
		int8_t days_ = nWeek - mWeek;
		if (nWeek > mWeek) {
			days_ -= 7;
		}
		int64_t numberTime_ = getNumberTime();
		numberTime_ += (nWeeks * 604800);
		numberTime_ += (days_ * 86400);
		this->adjustTime(numberTime_);
	}
	
	void LocalTime::adjustTime(int8_t nHour, int8_t nMin, int8_t nSec)
	{
		mHour = nHour;
		mMin = nMin;
		mSec = nSec;
	}
	
	void LocalTime::adjustTime(int64_t nTime, int8_t nHour, int8_t nMin, int8_t nSec)
	{
		this->adjustTime(nTime);
		this->adjustTime(nHour, nMin, nSec);
	}
	
	void LocalTime::adjustTime(int64_t nTime)
	{
		time_t time_ = nTime;
		tm * tm_ = localtime(&time_);
		mYear = tm_->tm_year;
		mMonth = tm_->tm_mon;
		mWeek = tm_->tm_wday;
		mDay = tm_->tm_mday;
		mHour = tm_->tm_hour;
		mMin = tm_->tm_min;
		mSec = tm_->tm_sec;
	}
	
	void LocalTime::setYear(int16_t nYear)
	{
		mYear = nYear - 1900;
	}
	
	int16_t LocalTime::getYear()
	{
		return (mYear + 1900);
	}
	
	void LocalTime::setMonth(int8_t nMonth)
	{
		mMonth = nMonth - 1;
	}
	
	int8_t LocalTime::getMonth()
	{
		return (mMonth + 1);
	}
	
	void LocalTime::setWeek(int8_t nWeek)
	{
		mWeek = nWeek;
	}
	
	int8_t LocalTime::getWeek()
	{
		return mWeek;
	}
	
	void LocalTime::setDay(int8_t nDay)
	{
		mDay = nDay;
	}
	
	int8_t LocalTime::getDay()
	{
		return mDay;
	}
	
	void LocalTime::setHour(int8_t nHour)
	{
		mHour = nHour;
	}
	
	int8_t LocalTime::getHour()
	{
		return mHour;
	}
	
	void LocalTime::setMin(int8_t nMin)
	{
		mMin = nMin;
	}
	
	int8_t LocalTime::getMin()
	{
		return mMin;
	}
	
	void LocalTime::setSec(int8_t nSec)
	{
		mSec = nSec;
	}
	
	int8_t LocalTime::getSec()
	{
		return mSec;
	}
	
	int64_t LocalTime::getNumberTime()
	{
		struct tm tm_;
		tm_.tm_year = mYear;
		tm_.tm_mon = mMonth;
		tm_.tm_wday = mWeek;
		tm_.tm_mday = mDay;
		tm_.tm_hour = mHour;
		tm_.tm_min = mMin;
		tm_.tm_sec = mSec;
		return mktime(&tm_);
	}
	
	string LocalTime::getStringTime()
	{
		string result_("");
		result_ += convertValue<int16_t, string>(mYear + 1900);
		result_ += ".";
		result_ += convertValue<int8_t, string>(mMonth + 1);
		result_ += ".";
		result_ += convertValue<int8_t, string>(mDay);
		result_ += "|";
		result_ += convertValue<int8_t, string>(mHour);
		result_ += ":";
		result_ += convertValue<int8_t, string>(mMin);
		result_ += ":";
		result_ += convertValue<int8_t, string>(mSec);
		return result_;
	}
	
	string LocalTime::getTextTime()
	{
		string result_("");
		result_ += convertValue<int16_t, string>(mYear + 1900);
		result_ += ".";
		result_ += convertValue<int8_t, string>(mMonth + 1);
		result_ += ".";
		result_ += convertValue<int8_t, string>(mDay);
		result_ += " ";
		result_ += convertValue<int8_t, string>(mHour);
		result_ += ":";
		result_ += convertValue<int8_t, string>(mMin);
		result_ += ":";
		result_ += convertValue<int8_t, string>(mSec);
		return result_;
	}
	
	LocalTime::LocalTime()
		: mYear(0)
		, mMonth(0)
		, mWeek(0)
		, mDay(0)
		, mHour(0)
		, mMin(0)
		, mSec(0)
	{
	}
	
	LocalTime::LocalTime(const string& nTime)
	{
		string time_ = stringTrim(nTime, "");
		if ("" == time_) return;
		string::size_type pos = time_.find("|");
		string dateStr = time_.substr(0, pos);
		string timeStr = time_.substr(pos + 1);
		
		pos = dateStr.find(".");
		string tempStr = dateStr.substr(0, pos);
		int16_t year_ = convertValue<string, int16_t>(tempStr);
		this->setYear(year_);
		
		dateStr = dateStr.substr(pos + 1);
		pos = dateStr.find(".");
		tempStr = dateStr.substr(0, pos);
		int8_t month_ = convertValue<string, int8_t>(tempStr);
		this->setMonth(month_);
		
		tempStr = dateStr.substr(pos + 1);
		mDay = convertValue<string, int8_t>(tempStr);
		
		pos = timeStr.find(":");
		tempStr = timeStr.substr(0, pos);
		mHour = convertValue<string, int8_t>(tempStr);
		
		timeStr = timeStr.substr(pos + 1);
		pos = timeStr.find(":");
		tempStr = timeStr.substr(0, pos);
		mMin = convertValue<string, int8_t>(tempStr);
		
		tempStr = timeStr.substr(pos + 1);
		mSec = convertValue<string, int8_t>(tempStr);
	}
	
	LocalTime::LocalTime(int64_t nTime)
	{
		this->adjustTime(nTime);
	}
	
	LocalTime::LocalTime(int16_t nYear, int8_t nMonth, int8_t nDay)
		: mYear(nYear - 1900)
		, mMonth(nMonth - 1)
		, mWeek(0)
		, mDay(nDay)
		, mHour(0)
		, mMin(0)
		, mSec(0)
	{
		int64_t numberTime_ = this->getNumberTime();
		this->adjustTime(numberTime_);
	}
	
	LocalTime::LocalTime(int16_t nYear, int8_t nMonth, int8_t nDay, int8_t nHour, int8_t nMin, int8_t nSec)
		: mYear(nYear - 1900)
		, mMonth(nMonth - 1)
		, mWeek(0)
		, mDay(nDay)
		, mHour(nHour)
		, mMin(nMin)
		, mSec(nSec)
	{
		int64_t numberTime_ = this->getNumberTime();
		this->adjustTime(numberTime_);
	}
	
	LocalTime::~LocalTime()
	{
		mYear = 0;
		mMonth = 0;
		mWeek = 0;
		mDay = 0;
		mHour = 0;
		mMin = 0;
		mSec = 0;
	}
	
}
