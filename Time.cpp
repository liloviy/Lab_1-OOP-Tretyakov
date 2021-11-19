#include "Time.h"
#include <iostream>	
Time::Time()
{
	SetHour(0);
	SetMinute(0);
	stringtime = ToStringTime();
}

Time::Time(short value_hour, short value_minute)
{
	try
	{
		if (value_hour < 13 && value_hour>0)
			 SetHour(value_hour);
		else
		{
			SetHour(0);
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
			SetMinute(value_minute);
		else
		{
			SetMinute(0);
			throw exception("Minute cannot be set");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	stringtime = ToStringTime();
}

Time::Time(const Time& ob)
{
	stringtime = ob.stringtime;
};

Time::~Time()
{
	delete[] stringtime;
}

char* Time::ToStringTime()
{
	char* string = new char[255];
	sprintf_s(string, 25, "%d:%d",GetHour(), GetMinute());
	return string;
}