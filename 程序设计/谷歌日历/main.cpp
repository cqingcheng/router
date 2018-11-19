#include <iostream>

using namespace std;




int main()
{
    cout<<"BEGIN:VCALENDAR"<<endl;
    cout<<"VERSION:2.0"<<endl;
    cout<<"PRODID:iCal4j v1.0//EN"<<endl;

    int date=20180305;
    //第一周
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangong"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:zuqiuchujiban"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:diqiukexuegailun"<<endl;
    cout<<"END:VEVENT"<<endl;

    ++date;//zhousan
      cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T070000"<<endl;
    cout<<"DTEND:"<<date<<"T083000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;

        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//zhousi
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangongyudianzijishu"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:diqiukexuegailun"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//zhouwu
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;

    date=date+3;
   //第二周
    while(date<20180331){
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:shenghuozhongdejingjixue"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangong"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:zuqiuchujiban"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:diqiukexuegailun"<<endl;
    cout<<"END:VEVENT"<<endl;

    ++date;//周三
      cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T070000"<<endl;
    cout<<"DTEND:"<<date<<"T083000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周四
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangongyudianzijishu"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:diqiukexuegailun"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周五
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
    date=date+3;
    }
//第五周
    date=20180402;
    while(date<20180427){
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:shenghuozhongdejingjixue"<<endl;
    cout<<"END:VEVENT"<<endl;

    ++date;//周二
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangong"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:zuqiuchujiban"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:diqiukexuegailun"<<endl;
    cout<<"END:VEVENT"<<endl;

    ++date;//周三
      cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T070000"<<endl;
    cout<<"DTEND:"<<date<<"T083000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T160500"<<endl;
    cout<<"DTEND:"<<date<<"T174000"<<endl;
    cout<<"SUMMARY:shengyaguihuayujiuyezhidao"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周四
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangongyudianzijishu"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:diqiukexuegailun"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周五
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
    date=date+3;
    }
    date=20180430;
    while(date<20180511){
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T140000"<<endl;
    cout<<"DTEND:"<<date<<"T153000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T190000"<<endl;
    cout<<"DTEND:"<<date<<"T203000"<<endl;
    cout<<"SUMMARY:shenghuozhongdejingjixue"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;
    if(date==20180431){date=20180501;}//周二
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangong"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:zuqiuchujiban"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周三
      cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T070000"<<endl;
    cout<<"DTEND:"<<date<<"T083000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:digital logic"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T163500"<<endl;
    cout<<"DTEND:"<<date<<"T18000"<<endl;
    cout<<"SUMMARY:shengyaguihuayujiuyezhidao"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周四
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:diangongyudianzijishu"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周五
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
    date=date+3;
}
    //十一周
    while(date<20180617){
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周二
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:zuqiuchujiban"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周三
      cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T070000"<<endl;
    cout<<"DTEND:"<<date<<"T083000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:c++"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周四
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:English"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周五
    if(date==20180532){date=20180601;}
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:c++"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
       date=date+3;
    }//16周


     while(date<20180630){
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周二
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:zuqiuchujiban"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周三
      cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T070000"<<endl;
    cout<<"DTEND:"<<date<<"T083000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:c++"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周四
    ++date;//周五
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:c++"<<endl;
    cout<<"END:VEVENT"<<endl;
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
       date=date+3;
     }
     date=20180702;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:Advanced mathematics"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周二
        cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T100500"<<endl;
    cout<<"DTEND:"<<date<<"T114000"<<endl;
    cout<<"SUMMARY:zuqiuchujiban"<<endl;
    cout<<"END:VEVENT"<<endl;
       cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T143000"<<endl;
    cout<<"DTEND:"<<date<<"T160000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
    ++date;//周三
    ++date;//周四
    ++date;//周五
    cout <<"BEGIN:VEVENT" << endl;
    cout<<"DTSTART:"<<date<<"T080000"<<endl;
    cout<<"DTEND:"<<date<<"T093000"<<endl;
    cout<<"SUMMARY:lisanshuxue"<<endl;
    cout<<"END:VEVENT"<<endl;
    cout<<"END:VCALENDAR"<<endl;
    return 0;
}
