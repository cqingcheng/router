#include <iostream>
using namespace std;
int strlen(string &d);
//Strcat����
void strcat(char *sec,char *src)//ָ��
{
    while(*sec){++sec;}
    while(*src){
        *sec=*src;
        ++sec;
        ++src;
    }
    *sec=0;
}
void strcat(string &a,const string &b)//��������
{
    a+=b;
}
//Strncpy����
void strncpy(string &a, string &b,int n)
{
   int m=0,q;
   q=strlen(b);
   if(n>q){cout<<"�ַ�������"<<endl;}
   else{while(n){
    a[m]=b[m];
    --n;
    ++m;
   }
   }
}
int strcmp(const string &a,const string &b)//�Ƚ��ַ�����С
{
    if(a<b){return -1;}
    if(a==b){return 0;}
    return 1;
}
int strlen(string &d)//�ַ�������
{
     int counter=0;
     for(;d[counter];++counter);
     return counter;
}

void strlwr(string &a)//��תС
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
    cout<<"ͨ��ָ��ʵ�ֵĽ��"<<a<<endl;*/
    int i,n;
    string s1,s2;
    cout<<"�����һ���ַ�����";
    cin>>s1;
    cout<<"����ڶ����ַ�����";
    cin>>s2;
    strcat(s1,s2);
    cout<<"strcat�������: "<<s1<<endl;
    i=strcmp(s1,s2);
    cout<<"strcmp���������"<<i<<endl;
    cout<<""<<s1<<"�ĳ���Ϊ��"<<strlen(s1)<<endl;
    cout<<"��������Ҫת��ΪСд�ַ�����";
    cin>>s1;
    strlwr(s1);
    cout<<"ת�����Ϊ"<<s1<<endl;
    cout<<"��������Ҫת��Ϊ��д�ַ�����";
    cin>>s1;
    strupr(s1);
    cout<<"ת�����Ϊ"<<s1<<endl;
    cout<<"�������滻���ַ�����";
    cin>>s2;
    cout<<"��������Ҫ�滻�ĳ��ȣ�";
    cin>>n;
    strncpy(s1,s2,n);
    cout<<"���Ϊ"<<s1<<endl;
    return 0;
}
