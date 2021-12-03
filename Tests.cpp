#include "Tests.h"
#include "DateTime.h"
#include <iostream>
#include <cassert>
#include "Event.h"
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
	value.SetDay(1);
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

void Tests::TestPlusOb()
{
	DateTime value1(5, 5, 5, 5, 5);
	DateTime value2 (1, 1, 1, 1, 1);
	DateTime value3 = value1 + value2;
	assert(value3.GetDay() == 6);
	assert(value3.GetMonth() == 6);
	assert(value3.GetYear() == 6);
	assert(value3.GetHour() == 6);
	assert(value3.GetMinute() == 6);
	cout << "Tests complete"<<endl ;
}

void Tests::TestMinusOb()
{
	DateTime value1(5, 5, 5, 5, 5);
	DateTime value2(1, 1, 1, 1, 1);
	DateTime value3 = value1 - value2;
	assert(value3.GetDay() == 4);
	assert(value3.GetMonth() == 4);
	assert(value3.GetYear() == 4);
	assert(value3.GetHour() == 4);
	assert(value3.GetMinute() == 4);
	cout << "Tests complete"<<endl;
}

void Tests::TestEqualOb()
{
	DateTime value1(5, 5, 5, 5, 5);
	DateTime value2(1, 1, 1, 1, 1);
	DateTime value3 = value1 = value2;
	assert(value3.GetDay() == 1);
	assert(value3.GetMonth() == 1);
	assert(value3.GetYear() == 1);
	assert(value3.GetHour() == 1);
	assert(value3.GetMinute() == 1);
	cout << "Tests complete"<<endl;
}

void Tests::TestGetEvent()
{
	char name[13] = "fgdsvlsvnlf";
	Event name1(5,6,name);
	assert(strcmp(name1.GetEvent(),name)==0);
	cout << "Tests complete" << endl;
}

void Tests::TestSetEvent()
{
	char name[13] = "fgdsvnlsvnlf";
	Event name1;
	name1.SetEvent(name);
	assert(strcmp(name1.GetEvent(), name) == 0);
	cout << "Tests complete" << endl;
}

void Tests::TestFile()
{
	DateTime value(1, 1, 1, 1, 1);
	fstream fd;
	fd.open("file.txt", fstream::in | fstream::out | fstream::app);;
	{
		fd << value;
	}
	fd.close();
	DateTime value2;
	fd.open("file.txt", fstream::in | fstream::out | fstream::app);;
	{
		fd >> value2;
	}
	fd.close();
	assert(value.GetDay() == value2.GetDay());
	assert(value.GetMonth() == value2.GetMonth());
	assert(value.GetYear() == value2.GetYear());
	assert(value.GetHour() == value2.GetHour());
	assert(value.GetMinute() == value2.GetMinute());
	cout << "Tests complete" << endl;
}
void Tests::TestFileBin()
{
	DateTime value(1, 1, 1, 1, 1);
	DateTime value2;
	ofstream out("file.dat", ios::binary | ios::out);
	value.WriteInFile(out, value);
	out.close();
	
	ifstream in("file.dat", ios::binary | ios::in);
	value2 = value2.ReadForFile(in,value2);
	in.close();
	assert(value.GetDay() == value2.GetDay());
	assert(value.GetMonth() == value2.GetMonth());
	assert(value.GetYear() == value2.GetYear());
	assert(value.GetHour() == value2.GetHour());
	assert(value.GetMinute() == value2.GetMinute());
	cout << "Tests complete" << endl;
}