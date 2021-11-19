#pragma once
#include "DateTime.h"
class Time:public DateTime
{
public:
	Time();
	Time(short value_hour, short value_minute);
	Time(const Time& ob);
	~Time();
	char* ToStringTime();
private:
	char* stringtime;
};

