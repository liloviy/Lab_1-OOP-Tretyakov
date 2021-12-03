#include <iostream>
#include "DateTime.h"
#include "Time.h"
#include "Event.h"
#include "Tests.h"
#include <fstream> 
using namespace std;

ostream& operator <<(ostream& os, const DateTime& ob)
{
 
    os << ob.year_<<" "<<ob.month_<<" "<<ob.day_<<" "<<ob.hour_<<" "<<ob.minute_;
    return os;
}

istream& operator >>(istream& is, DateTime& ob)
{
    is >> ob.year_ >> ob.month_ >> ob.day_ >> ob.hour_ >> ob.minute_;
    return is;
}

int main()
{
    /*fstream fd;
    fd.open("file.txt",fstream::in | fstream::out | fstream::app);*/
   // ofstream out("file.dat", ios::binary | ios::out); //Открываем файл в двоичном режиме для записи
   // ifstream in("file.dat", ios::binary | ios::in); //Открываем файл в двоичном режиме только для чтения
    //try
    //{
    //    if (in.is_open())
    //    {
    //        DateTime time(4,3,2,1,3);
    //        DateTime t;
    //        t = t.ReadForFile(in, t);
    //        cout << t;
    //            /*    fd << time;*/
    //       
    //        /*int tmp_day, tmp_month, tmp_year, tmp_hour, tmp_minute;
    //        in.read()*/
    //        /*out << time;*/
    //         //Записываем в файл число y
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
    //in.close(); //Закрываем файл.close();
    Tests t = Tests();
    t.TestFile();
    t.TestFileBin();
    cin.get();
    return 0;
}
