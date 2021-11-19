#pragma once
#include "DateTime.h"
class Event : public DateTime
{
public:
	Event();
	Event(short value_hour, short value_minute, char* name);
	Event(const Event& ob);
	~Event();
	char* ToStringTimeEvent();
	char* GetEvent();
	void SetEvent(char*nameevent);
private:
	char* stringevent;
	char* nameEvent;
};

