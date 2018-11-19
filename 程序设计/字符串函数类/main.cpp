#include <iostream>
#include<string>
using namespace std;

class zfc
{
   public:
       zfc();
       zfc(string a);
       void show();
       int s_strlen();
       void s_strcat(const string c1);
       void s_strncpy(const string c2,int n);
       int s_strcmp(const string c3);
       void s_strlwr();
       void s_strupr();
    private:
        string x;
};
zfc::zfc(string a){x=a;}
void zfc::show(){
     cout<<"��ʱ�ַ���Ϊ��"<<x<<endl;
}
int zfc::s_strlen(){
     int n=0;
     while(x[n]){++n;}
     return n;
}
void zfc::s_strcat(const string c1){
     x=x+c1;
}
int strlen(const string c){
    int n=0;
     while(c[n]){++n;}
     return n;
}
int zfc::s_strcmp(const string c3){
     if(x<c3){return -1;}
    if(x==c3){return 0;}
    if(x>c3){return 1;}
}
void zfc::s_strncpy(const string c2,int n){
  int m;
  m=strlen(c2);
  if(n>m){cout<<"�����ַ������ȹ�С";}
  else{
    while(n){
        x[n]=c2[n];
        --n;
    }
  }
}
void zfc::s_strlwr()//��תС
{
    int b=0;
    for(;x[b];++b){
        if(x[b]>='A'&&x[b]<='Z')x[b]=x[b]+32;
    }
}
void zfc::s_strupr(){
     int b=0;
    for(;x[b];++b){
        if(x[b]>='a'&&x[b]<='z')x[b]=x[b]-32;
    }
}
int main()
{
    int n;
    string s1,s2,s3;
    cout<<"�������һ���ַ�����";
    cin>>s1;
    zfc s(s1);
    cout<<"���ַ�������Ϊ��"<<s.s_strlen()<<endl;
    cout<<"������ڶ����ַ�����";
    cin>>s2;
    s.s_strcat(s2);
    s.show();
    cout<<"�������滻���ַ�����";
    cin>>s3;
    cout<<"�������滻����";
    cin>>n;
    s.s_strncpy(s3,n);
    s.show();
    cout<<"������Ƚϵ��ַ�����";
    cin>>s3;
    cout<<s.s_strcmp(s3)<<endl;
    s.s_strlwr();
    s.show();
    s.s_strupr();
    s.show();
    return 0;
}
