#pragma once

namespace cc {
	
	class LocalTime : noncopyable
	{
	public:
		void adjustWeekDay(int8_t nWeeks, int8_t nWeek, int8_t nHour, int8_t nMin, int8_t nSec);
		void adjustWeekDay(int8_t nWeeks, int8_t nWeek);
		void adjustTime(int64_t nTime, int8_t nHour, int8_t nMin, int8_t nSec);
		void adjustTime(int8_t nHour, int8_t nMin, int8_t nSec);
		void adjustTime(int64_t nTime);
		void setYear(int16_t nYear);
		int16_t getYear();
		void setMonth(int8_t nMonth);
		int8_t getMonth();
		void setWeek(int8_t nWeek);
		int8_t getWeek();
		void setDay(int8_t nDay);
		int8_t getDay();
		void setHour(int8_t nHour);
		int8_t getHour();
		void setMin(int8_t nMin);
		int8_t getMin();
		void setSec(int8_t nSec);
		int8_t getSec();
		int64_t getNumberTime();
		string getStringTime();
		string getTextTime();
		
		LocalTime();
		LocalTime(int64_t nTime);
		LocalTime(const string& nTime);
		LocalTime(int16_t nYear, int8_t nMonth, int8_t nDay);
		LocalTime(int16_t nYear, int8_t nMonth, int8_t nDay, int8_t nHour, int8_t nMin, int8_t nSec);
		~LocalTime();
		
	private:
		int16_t mYear;
		int8_t mMonth;
		int8_t mWeek;
		int8_t mDay;
		int8_t mHour;
		int8_t mMin;
		int8_t mSec;
	};
	
}
