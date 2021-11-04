#include "DateTime.h"
#include <iostream>

DateTime::DateTime()
{
	cnt++;
	day_ = 0;
	month_ = 0;
	year_ = 0;
	hour_ = 0;
	minute_ = 0;
	string = ToString();
}

DateTime::DateTime(short value_day, short value_month, short value_year, short value_hour, short value_minute)
{
	try
	{
		if (value_day < 32 && value_day > 0)
			day_ = value_day;
		else
		{
			day_ = 0;
			throw exception("Day cannot be set");
		}
	}
	catch(const std::exception & ex)
	{
		cout << ex.what() << endl;
	}
	try
	{
		if (value_month < 13 && value_month > 0)
			month_ = value_month;
		else
		{
			month_ = 0;
			throw exception("Month cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	try
	{
		if (value_year>0)
			year_ = value_year;
		else
		{
			year_ = 0;
			throw exception("Year cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	try
	{
		if (value_hour < 25 && value_hour>0)
			hour_ = value_hour;
		else
		{
			hour_ = 0;
			throw exception("Hour cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	try
	{
		if (value_minute < 61 && value_minute>0)
			minute_ = value_minute;
		else
		{
			minute_ = 0;
			throw exception("Minute cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}	
	string = ToString();
	cnt++;
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
	delete [] string;
}

short DateTime::GetDay()
{
	return day_;
}

void DateTime::SetDay(short value_day)
{
	try
	{
		if (value_day > 0 && value_day < 32)
		{
			day_ = value_day;
		}
		else
		{
			throw exception("Day cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}	
}

short DateTime::GetMonth()
{
	return month_;
}

void DateTime::SetMonth(short value_month)
{
	try
	{
		if (value_month > 0 && value_month < 13)
		{
			month_ = value_month;
		}
		else
		{
			throw exception("Month cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

short DateTime::GetYear()
{
	return year_;
}

void DateTime::SetYear(short value_year)
{
	try
	{
		if (value_year > 0)
		{
			year_ = value_year;
		}
		else
		{
			throw exception("Year cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

short DateTime::GetHour()
{
	return hour_;
}

void DateTime::SetHour(short value_hour)
{
	try
	{
		if (value_hour > -1 && value_hour<25)
		{
			hour_ = value_hour;
		}
		else
		{
			throw exception("Hour cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}	
}

short DateTime::GetMinute()
{
	return minute_;
}

void DateTime::SetMinute(short value_minute)
{
	try
	{
		if (value_minute > -1 && value_minute < 61)
		{
			minute_ = value_minute;
		}
		else
		{
			throw exception("Minutes cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

short DateTime::PlusDay()
{
	day_++;
	if ((month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12) && day_ == 32)
	{
		day_ = 1;
		if (month_ == 12)
		{
			year_++;
			month_ = 1;
		}
		else
			month_++;
	}
	if (year_ % 4 != 0 && month_ == 2 && day_ == 28)
	{
		day_ = 1;
		month_++;
	}
	if (year_ % 4 == 0 && month_ == 2 && day_ == 29)
	{
		day_ = 1;
		month_++;
	}
	if ((month_ == 4 || month_ == 6 || month_ == 9 || month_ == 1) && day_ == 31)
	{
		day_ = 1;
		month_++;
	}
	return day_;
}

short DateTime::MinusDay()
{
	day_--;
	if ((month_ == 12 || month_ == 10 || month_ == 7 || month_ == 5) && day_ == 0)
	{
		day_ = 30;
		month_--;
	}
	if ((month_ == 11 || month_ == 9 || month_ == 6 || month_ == 4) && day_ == 0)
	{
		day_ = 31;
		month_--;
	}
	if (year_ % 4 == 0 && month_ == 3 && day_ == 0)
	{
		day_ = 29;
		month_--;
	}
	if (year_ % 4 != 0 && month_ == 3 && day_ == 0)
	{
		day_ = 28;
		month_--;
	}
	if ((month_ == 8 || month_ == 1) && day_ == 0)
	{
		day_ = 31;
		if (month_ == 1)
		{
			month_ = 12;
			year_--;
		}
		else
			month_--;
	}
	return day_;
}

short DateTime::PlusMonth()
{
	month_++;
	if (month_ == 13)
	{
		month_ = 1;
		year_++;
	}
	return month_;
}

short DateTime::MinusMonth()
{
	month_--;
	if (month_ == 0)
	{
		month_ = 12;
		year_--;
	}
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
	if (year_ == 0)
		year_ = 0;
	return year_;
}

short DateTime::PlusHour()
{
	hour_++;
	if (hour_ == 24)
	{
		hour_ = 0;
		day_++;
	}
	return hour_;
}

short DateTime::MinusHour()
{
	hour_--;
	if (hour_ == -1)
	{
		hour_ = 23;
		day_--;
	}
	return hour_;
}

short DateTime::PlusMinute()
{
	minute_++;
	if (minute_ == 61)
	{
		minute_ = 0;
		hour_++;
	}
	return minute_;
}

short DateTime::MinusMinute()
{
	minute_--;
	if (minute_ == -1)
	{
		minute_ = 59;
		hour_--;
	}
	return minute_;
}

char* DateTime::ToString()
{	
	char* string = new char[255];
	sprintf_s(string,25,"%d-%d-%d %d:%d", year_,month_, day_, hour_,minute_);
	return string;
}

int DateTime::cnt = 0;

DateTime operator + (const DateTime& ob1, const DateTime& ob2)
{
	DateTime tmp;
	tmp.day_ = ob1.day_ + ob2.day_;
	tmp.month_ = ob1.month_ + ob2.month_;
	tmp.year_ = ob1.year_ + ob2.year_;
	tmp.hour_ = ob1.hour_ + ob2.hour_;
	tmp.minute_ = ob1.minute_ + ob2.minute_;
	return CheckingRedeploymentPlus(tmp);
};

DateTime operator - (const DateTime& ob1, const DateTime& ob2)
{
	DateTime tmp;
	tmp.day_ = ob1.day_ - ob2.day_;
	tmp.month_ = ob1.month_ - ob2.month_;
	tmp.year_ = ob1.year_ - ob2.year_;
	tmp.hour_ = ob1.hour_ - ob2.hour_;
	tmp.minute_ = ob1.minute_ - ob2.minute_;
	return CheckingRedeploymentMinus(tmp);
}