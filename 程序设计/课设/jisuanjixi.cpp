#include <iostream>
#include "lei3.h"
using namespace std;
jisuanjixi::jisuanjixi(int i):student(3){
       zucheng=0;
       tixi=0;
       huibian=0;
       cout<<"�������������ԭ��ĳɼ�:";
       cin>>zucheng;
       cout<<"������������ϵ�ṹ�ĳɼ�:";
       cin>>tixi;
       cout<<"�����������Գɼ��ĳɼ�:";
       cin>>huibian;
}
void jisuanjixi::show(){
    show1();
    cout<<"     ���ԭ��ɼ���"<<zucheng;
    cout<<"     ��ϵ�ṹ�ɼ���"<<tixi;
    cout<<"     ������Գɼ���"<<huibian<<endl;
}

void jisuanjixi::chaxun(class jisuanjixi *jhead){
    class jisuanjixi *h;
    h=jhead;
    int n=0,m=0;
    cout<<"1.ѧ�Ų���  2.��������"<<endl;
    cout<<"��ѡ����Ҫ���ҵķ���:";
    cin>>n;
    while(n!=1&&n!=2){
        cout<<"ѡ�������������"<<endl;
        cin>>n;
    }
    if(n==1){
            int fid;
            cout<<"������ѧ��ѧ�ţ�";
            cin>>fid;
            while(h!=NULL) {
                if(h->idfind(fid)){
                    h->show();
                    ++m;
                }
                h=h->next;
            }
    }
     if(n==2){
            string fname;
            cout<<"������ѧ��������";
            cin>>fname;
            while(h!=NULL) {
                if(h->namefind(fname)){
                    h->show();
                    ++m;
                }
                h=h->next;
            }
      if(m==0)cout<<"���޴���";

    }
}

void jisuanjixi::add(class jisuanjixi *jhead){
   class jisuanjixi*h,*c;
       c=new jisuanjixi(0);
   h=jhead;
   while((h->next)!=NULL){h=h->next;}
   h->next=c;
   c->next=NULL;
}

void jisuanjixi::shanchu(class jisuanjixi *jhead){
    int nid;
    class jisuanjixi *h,*pre;
    h=jhead;
    cout<<"������ɾ��ѧ����ѧ��:";
    cin>>nid;
    if(h->idfind(nid)){
        jhead=jhead->next;
        delete h;
    }
    else{
            while(h!=NULL){
                    pre=h;
                h=h->next;
                if(h->idfind(nid)){
                pre->next=h->next;
                delete h;
                 break;
                }
            }
    }
    cout<<"��ɾ��ѧ��Ϊ��"<<nid<<"ѧ������Ϣ"<<endl;
}

float jisuanjixi::qpingjun(){
     float n=0,m=0;
     m=gpingjun()*3;
     n=m+zucheng+tixi+huibian;
     n/=6;
     return n;
}
