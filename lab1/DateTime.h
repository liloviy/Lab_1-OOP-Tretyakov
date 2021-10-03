#pragma once
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
private:
	short day_;
	short month_;
	short year_;
	short hour_;
	short minute_;
};

