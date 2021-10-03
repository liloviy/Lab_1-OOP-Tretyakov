#include <iostream>
#include "DateTime.h"
#include "Tests.h"
using namespace std;

int main()
{
    DateTime time(5,5,1,2,3);
    cout << time.ToString()<<endl;
    Tests tester;
	try
	{
		tester.TestGetValue();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	try
	{
		tester.TestSetValue();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	cout << DateTime::cnt;
    cin.get();
    return 0;
}
