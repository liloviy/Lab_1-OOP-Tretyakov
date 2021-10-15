#include <iostream>
#include "DateTime.h"
#include "Tests.h"
#include <fstream> 
using namespace std;

ostream& operator <<(ostream& os, const DateTime& ob)
{
 
    os << ob.year_<<"-"<<ob.month_<<"-"<<ob.day_<<" "<<ob.hour_<<":"<<ob.minute_;
    return os;
}

istream& operator >>(istream& is, DateTime& ob)
{
    is >>ob.year_>>ob.month_>>ob.day_>>ob.hour_>>ob.minute_;
    return is;
}

int main()
{
    DateTime time1(21,12,2002,22,21);
    DateTime time2(212, 122, 20022, 222, 212);
    fstream fd;
    fd.open("file.txt",fstream::in | fstream::out | fstream::app);
    try
    {
        if (fd.is_open())
        {
            /*fd << time1<<"\n";
            fd << time2;*/
            DateTime time;
            fd >> time;
            cout << time;
            /*while (true)
            {
                DateTime time;
                fd >> time;
                if (fd.eof())
                    break;
                cout << time;
            }*/
        }
        else
        {
            throw exception("Can not open file");
        }
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl;
    }
    fd.close();
    cin.get();
    return 0;
}
