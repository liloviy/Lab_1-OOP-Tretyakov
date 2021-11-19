#include "Event.h"
#include <iostream>	
Event::Event()
{
	SetHour(0);
	SetMinute(0);
	stringevent = ToStringTimeEvent();
	nameEvent = new char[255];
	strcpy_s(nameEvent,25, "no name");
}

Event::Event(short value_hour, short value_minute,char* name)
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
	stringevent = ToStringTimeEvent();
	nameEvent = new char[255];
	strcpy_s(nameEvent,25, name);
}

Event::Event(const Event& ob)
{
	stringevent = ob.stringevent;
	nameEvent = ob.nameEvent;
};

Event::~Event()
{
	delete[] stringevent;
}

char* Event::GetEvent()
{
	return nameEvent;
}

void Event::SetEvent(char* nameevent)
{
	strcpy_s(this->nameEvent, 25, nameevent);
}

char* Event::ToStringTimeEvent()
{
	char* string = new char[255];
	sprintf_s(string, 25, "%s %d:%d",nameEvent, GetHour(), GetMinute());
	return string;
}