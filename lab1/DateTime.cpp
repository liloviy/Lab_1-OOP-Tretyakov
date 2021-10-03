#include "DateTime.h"
#include <iostream>

DateTime::DateTime()
{
	cnt++;
}

DateTime::DateTime(short value_day, short value_month, short value_year, short value_hour, short value_minute)
{
	if (value_day < 32 && value_month < 13 && value_hour < 25 && value_minute < 61)
	{
		day_ = value_day;
		month_ = value_month;
		year_ = value_year;
		hour_ = value_hour;
		minute_ = value_minute;
		cnt++;
	}
}

DateTime::DateTime(const DateTime& ob)
{
	day_ = ob.day_;
	month_ = ob.month_;
	year_ = ob.year_;
	hour_ = ob.hour_;
	minute_ = ob.minute_;
	cnt++;
};

DateTime::~DateTime()
{

}

short DateTime::GetDay()
{
	return day_;
}

void DateTime::SetDay(short value_day)
{
	day_ = value_day;
}

short DateTime::GetMonth()
{
	return month_;
}

void DateTime::SetMonth(short value_month)
{
	month_ = value_month;
}

short DateTime::GetYear()
{
	return year_;
}

void DateTime::SetYear(short value_year)
{
	year_ = value_year;
}

short DateTime::GetHour()
{
	return hour_;
}

void DateTime::SetHour(short value_hour)
{
	hour_ = value_hour;
}

short DateTime::GetMinute()
{
	return minute_;
}

void DateTime::SetMinute(short value_minute)
{
	minute_ = value_minute;
}

short DateTime::PlusDay()
{
	day_++;
	return day_;
}

short DateTime::MinusDay()
{
	day_--;
	return day_;
}

short DateTime::PlusMonth()
{
	month_++;
	return month_;
}

short DateTime::MinusMonth()
{
	month_--;
	return month_;
}

short DateTime::PlusYear()
{
	year_++;
	return year_;
}

short DateTime::MinusYear()
{
	year_--;
	return year_;
}

short DateTime::PlusHour()
{
	hour_++;
	return hour_;
}

short DateTime::MinusHour()
{
	hour_--;
	return hour_;
}

short DateTime::PlusMinute()
{
	minute_++;
	return minute_;
}

short DateTime::MinusMinute()
{
	minute_--;
	return minute_;
}

char* DateTime::ToString()
{	
	char* string = new char[255];
	sprintf_s(string,25,"%d.%d.%d.%d.%d",day_,month_,year_,hour_,minute_);
	return string;
	delete[] string;
}

int DateTime::cnt = 0;