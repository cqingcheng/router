#include <iostream>
#define max 1000
using namespace std;

struct xinxi{
  int a,b;
}task[max];

int choose(int now,int all){
     int t=-1,n;
     static int c=-1;
     for(n=0;n<all;++n){
        if(task[n].b>=now){
                if(c==-1){t=n;++c;}
                else{
                    if(task[n].a>task[t].a&&t!=n){t=n;}
                }
       }
     }
     task[t].a=-1;
   return t;
}

void tranvest(int time){
    int result[max];
    int num,r;
    num=time;
    r=time;
    for(;num>=0;){
        --num;
        result[num]=choose(time,r);
        --time;
    }
    for(num=0;num<r;++num){
        if(result[num]==-1){break;}
        cout<<result[num]+1<<"   ";
    }
}

int main()
{
    int n,m;
    cout<<"请输入时间片：";
    cin>>n;
    for(m=0;m<n;++m){cout<<"输入处理顺序：";cin>>task[m].a;}
    for(m=0;m<n;++m){cout<<"输入效益："<<endl;cin>>task[m].b;}
    tranvest(n);
}
