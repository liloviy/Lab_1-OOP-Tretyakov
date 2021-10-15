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
	DateTime& operator = (const DateTime& ob)
	{
		day_ = ob.day_;
		month_ = ob.month_;
		year_ = ob.year_;
		hour_ = ob.hour_;
		minute_ = ob.minute_;
		cnt++;
		return *this;
	};
	DateTime operator + (const DateTime& ob)
	{
		DateTime tmp;
		tmp.day_ = this->day_ + ob.day_;
		tmp.month_ = this->month_ + ob.month_;
		tmp.year_ = this->year_ + ob.year_;
		tmp.hour_ = this->hour_ + ob.hour_;
		tmp.minute_ = this->minute_ + ob.minute_;
		if (tmp.minute_ > 60)
		{
			if (tmp.minute_ == 120)
			{
				tmp.hour_ += 2;
				tmp.minute_ = 0;
			}
			else
			{
				tmp.hour_++;
				tmp.minute_ = tmp.minute_ % 60;
			}
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
	DateTime operator - (const DateTime& ob)
	{
		DateTime tmp;
		tmp.day_ = this->day_ - ob.day_;
		tmp.month_ = this->month_ - ob.month_;
		tmp.year_ = this->year_ - ob.year_;
		tmp.hour_ = this->hour_ - ob.hour_;
		tmp.minute_ = this->minute_ - ob.minute_;
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
	friend ostream& operator <<(ostream& os, const DateTime& ob);
	friend istream& operator >>(istream& is, DateTime& ob);
private:
	short day_;
	short month_;
	short year_;
	short hour_;
	short minute_;
};

