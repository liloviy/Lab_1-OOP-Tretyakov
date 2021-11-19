#pragma once
#include <cmath>
#include <fstream> 
using namespace std;

class DateTime
{
public:
	DateTime();
	DateTime(short value_day, short value_month, short value_year, short value_hour, short value_minute);
	DateTime(const DateTime& ob);
	~DateTime();
	static int cnt;
	short GetDay();
	void SetDay(short valueday);
	short GetMonth();
	void SetMonth(short valuemonth);
	short GetYear();
	void SetYear(short valueyear);
	short GetHour();
	void SetHour(short valuehour);
	short GetMinute();
	void SetMinute(short valueminute);
	short PlusDay();
	short MinusDay();
	short PlusMonth();
	short MinusMonth();
	short PlusYear();
	short MinusYear();
	short PlusHour();
	short MinusHour();
	short PlusMinute();
	short MinusMinute();
	char* ToString();
	friend DateTime CheckingRedeploymentPlus(DateTime& tmp)
	{
		if (tmp.minute_ > 60)
		{
			tmp.hour_++;
			tmp.minute_ = tmp.minute_ % 60;
		}
		if (tmp.hour_ > 24)
		{
			if (tmp.hour_ == 48)
			{
				tmp.day_ += 2;
				tmp.hour_ = 0;
			}
			else
			{
				tmp.day_++;
				tmp.hour_ = tmp.hour_ % 24;
			}
		}
		if (tmp.day_ > 31)
		{
			if (tmp.day_ == 62)
			{
				tmp.month_ += 2;
				tmp.day_ = 0;
			}
			else
			{
				tmp.month_++;
				tmp.day_ = tmp.day_ % 31;
			}
		}
		if (tmp.month_ > 12)
		{
			if (tmp.month_ == 24)
			{
				tmp.year_ += 2;
				tmp.month_ = 0;
			}
			else
			{
				tmp.year_++;
				tmp.month_ = tmp.month_ % 12;
			}
		}
		return tmp;
	};
	friend DateTime CheckingRedeploymentMinus(DateTime& tmp)
	{
		if (tmp.minute_ < 0)
		{
			tmp.minute_ = 60 - abs(tmp.minute_);
			tmp.hour_--;
		}
		if (tmp.hour_ < 0)
		{
			tmp.hour_ = 24 - abs(tmp.hour_);
			tmp.day_--;
		}
		if (tmp.day_ < 0)
		{
			tmp.day_ = 31 - abs(tmp.day_);
			tmp.month_--;
		}
		if (tmp.month_ < 0)
		{
			tmp.month_ = 12 - abs(tmp.month_);
			tmp.year_--;
		}
		if (tmp.year_ < 0)
		{
			tmp.year_ = 0;
		}
		return tmp;
	}
	DateTime& operator = (const DateTime& ob)
	{
		day_ = ob.day_;
		month_ = ob.month_;
		year_ = ob.year_;
		hour_ = ob.hour_;
		minute_ = ob.minute_;
		for (int i = 0; i<16; i++)
			string[i] = ob.string[i];
		return *this;
	};
	friend DateTime operator + (const DateTime& ob1, const DateTime& ob2);
	DateTime operator + (int hour)
	{
		DateTime tmp;
		tmp.day_ = this->day_;
		tmp.month_ = this->month_;
		tmp.year_ = this->year_;
		tmp.hour_ = this->hour_;
		tmp.minute_ = this->minute_;
		tmp.year_ += hour / 8760;
		hour = hour % 8760;
		tmp.month_ += hour / 730;
		hour = hour % 730;
		tmp.day_ += hour / 24;
		hour = hour % 24;
		return CheckingRedeploymentPlus(tmp);
	};
	friend DateTime operator - (const DateTime& ob1, const DateTime& ob2);
	DateTime operator - (int hour)
	{
		DateTime tmp;
		tmp.day_ = this->day_ - hour;
		tmp.month_ = this->month_ - hour;
		tmp.year_ = this->year_ - hour;
		tmp.hour_ = this->hour_ - hour;
		tmp.minute_ = this->minute_ - hour;
		tmp.year_ += hour / 8760;
		hour = hour % 8760;
		tmp.month_ += hour / 730;
		hour = hour % 730;
		tmp.day_ += hour / 24;
		hour = hour % 24;
		return CheckingRedeploymentMinus(tmp);
	}
	operator char*()
	{
		return ToString();
	};
	friend ostream& operator <<(ostream& os, const DateTime& ob);
	friend istream& operator >>(istream& is, DateTime& ob);
private:
	short day_;
	short month_;
	short year_;
	short hour_;
	short minute_;
	char* string;
};

