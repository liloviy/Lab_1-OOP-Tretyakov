#include "Tests.h"
#include "DateTime.h"
#include <iostream>
using namespace std;

void Tests::TestGetValue()
{
	short value_day = 1, value_month = 2, value_year = 1, value_hour = 1, value_minute = 1;
	DateTime value(1, 1, 1, 1, 1);
	if (value.GetDay() != value_day)
		throw exception("Problem with get day");
	if (value.GetMonth() != value_month)
		throw exception("Problem with get month");
	if (value.GetYear() != value_year)
		throw exception("Problem with get year");
	if (value.GetHour() != value_hour)
		throw exception("Problem with get hour");
	if (value.GetMinute() != value_minute)
		throw exception("Problem with get minute");
}

void Tests::TestSetValue()
{
	DateTime value;
	value.SetDay(-5);
	value.SetMonth(1);
	value.SetYear(1);
	value.SetHour(1);
	value.SetMinute(1);
	if (value.GetDay() > 31 || value.GetDay() < 1)
		throw exception("Problem with set day");
	if (value.GetMonth() >12 || value.GetMonth() < 1)
		throw exception("Problem with set month");
	if (value.GetYear() <0)
		throw exception("Problem with set year");
	if (value.GetHour() >24 || value.GetHour() <1)
		throw exception("Problem with set hour");
	if (value.GetMinute() > 60 || value.GetMinute()<1)
		throw exception("Problem with set minute");
}

void Tests::TestMinusValue()
{
	short value_day = 1, value_month = 1, value_year = 1, value_hour = 1, value_minute = 1;
	DateTime value(2, 2, 2, 2, 2);
	if (value.MinusDay() != value_day)
		throw exception("Problem with minus day");
	if (value.MinusMonth() != value_month)
		throw exception("Problem with minus monnth");
	if (value.MinusYear() != value_year)
		throw exception("Problem with minus year");
	if (value.MinusHour() != value_hour)
		throw exception("Problem with minus hour");
	if (value.MinusMinute() != value_minute)
		throw exception("Problem with minus minute");
}

void Tests::TestPlusValue()
{
	short value_day = 2, value_month = 2, value_year = 2, value_hour = 2, value_minute = 2;
	DateTime value(1, 1, 1, 1, 1);
	if (value.PlusDay() != value_day)
		throw exception("Problem with plus day");
	if (value.PlusMonth() != value_month)
		throw exception("Problem with plus monnth");
	if (value.PlusYear() != value_year)
		throw exception("Problem with plus year");
	if (value.PlusHour() != value_hour)
		throw exception("Problem with plus hour");
	if (value.PlusMinute() != value_minute)
		throw exception("Problem with plus minute");
}


