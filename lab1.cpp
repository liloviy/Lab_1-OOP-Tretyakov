#include <iostream>
#include "DateTime.h"
#include "Time.h"
#include "Event.h"
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
    is >> ob.year_ >> ob.month_ >> ob.day_ >> ob.hour_ >> ob.minute_;
    return is;
}

int main()
{
   /* DateTime t1(2, 3, 4, 5, 6);
    cout << t1<<endl;
    Tests test=Tests();

    test.TestPlusOb();
    test.TestMinusOb();
    test.TestEqualOb();*/
    //fstream fd;
    //fd.open("file.txt",fstream::in | fstream::out | fstream::app);
    //try
    //{
    //    if (fd.is_open())
    //    {
    //        /*fd << time1<<"\n";
    //        fd << time2;*/
    //        DateTime time(4,3,2,1,3);
    //        fd << time;
    //        DateTime time2;
    //        fd >> time2;
    //        cout << time2;
    //        /*fd << time<<"/n";*/
    //        //DateTime time2;
    //        //while (!fd.eof())
    //        //{
    //        //    fd >> time2;
    //        //    //if (fd.eof())
    //        //    //    break;
    //        //}
    //        //cout << time2;
    //    }
    //    else
    //    {
    //        throw exception("Can not open file");
    //    }
    //}
    //catch (const std::exception& ex)
    //{
    //    cout << ex.what() << endl;
    //}
    //fd.close();
    /*char name[15]="fgdsvnlsvnlf";
    Event dwfw(5, 30,name);
    cout << dwfw.ToStringTimeEvent()<<endl;
    
    cout << dwfw.GetEvent();
    cout << endl;
    char name2[15] = "ffgh3223";
    dwfw.SetEvent(name2);
    cout << dwfw.ToStringTimeEvent();*/
    Tests test = Tests();
    test.TestSetEvent();
    test.TestGetEvent();
    cin.get();
    return 0;
}
