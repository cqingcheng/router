#include <iostream>
using namespace std;
int strlen(string &d);
//Strcat函数
void strcat(char *sec,char *src)//指针
{
    while(*sec){++sec;}
    while(*src){
        *sec=*src;
        ++sec;
        ++src;
    }
    *sec=0;
}
void strcat(string &a,const string &b)//引用连接
{
    a+=b;
}
//Strncpy函数
void strncpy(string &a, string &b,int n)
{
   int m=0,q;
   q=strlen(b);
   if(n>q){cout<<"字符串过短"<<endl;}
   else{while(n){
    a[m]=b[m];
    --n;
    ++m;
   }
   }
}
int strcmp(const string &a,const string &b)//比较字符串大小
{
    if(a<b){return -1;}
    if(a==b){return 0;}
    return 1;
}
int strlen(string &d)//字符串长度
{
     int counter=0;
     for(;d[counter];++counter);
     return counter;
}

void strlwr(string &a)//大转小
{
    int b=0;
    for(;a[b];++b){
        if(a[b]>='A'&&a[b]<='Z')a[b]=a[b]+32;
    }

}
void  strupr(string &a){
     int b=0;
    for(;a[b];++b){
        if(a[b]>='a'&&a[b]<='z')a[b]=a[b]-32;
    }
}

int main()
{
    /*char a[10],b[10];
    cin>>a>>b;
    strcat(a,b);
    cout<<"通过指针实现的结果"<<a<<endl;*/
    int i,n;
    string s1,s2;
    cout<<"输入第一个字符串：";
    cin>>s1;
    cout<<"输入第二个字符串：";
    cin>>s2;
    strcat(s1,s2);
    cout<<"strcat函数结果: "<<s1<<endl;
    i=strcmp(s1,s2);
    cout<<"strcmp函数结果："<<i<<endl;
    cout<<""<<s1<<"的长度为："<<strlen(s1)<<endl;
    cout<<"请输入需要转化为小写字符串：";
    cin>>s1;
    strlwr(s1);
    cout<<"转换结果为"<<s1<<endl;
    cout<<"请输入需要转化为大写字符串：";
    cin>>s1;
    strupr(s1);
    cout<<"转换结果为"<<s1<<endl;
    cout<<"请输入替换的字符串：";
    cin>>s2;
    cout<<"请输入需要替换的长度：";
    cin>>n;
    strncpy(s1,s2,n);
    cout<<"结果为"<<s1<<endl;
    return 0;
}
