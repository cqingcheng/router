#include <iostream>
#include "lei2.h"

using namespace std;
void shuxuexi::show(){
    show1();
    cout<<"       ʵ�亯���ɼ�:"<<shibian;
    cout<<"       ���������ɼ���"<<fanhan;
    cout<<"       ΢�ּ��γɼ���"<<weifen<<endl;
}


void shuxuexi::chaxun(class shuxuexi *shead){
    class shuxuexi *h;
    h=shead;
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


 void shuxuexi::add(class shuxuexi *shead){
   class shuxuexi*h,*c;
   float sbhs,fhfx,wfjh;

    cout<<"������ʵ�亯���ĳɼ�:";
       cin>>sbhs;
       cout<<"�����뷺�������ĳɼ�:";
       cin>>fhfx;
       cout<<"������΢�ּ��εĳɼ�:";
       cin>>wfjh;
       c=new shuxuexi(sbhs,fhfx,wfjh);
   h=shead;
   while((h->next)!=NULL){h=h->next;}
   h->next=c;
   c->next=NULL;
}

void shuxuexi::shanchu(class shuxuexi *shead){
    int nid;
    class shuxuexi *h,*pre;
    h=shead;
    cout<<"������ɾ��ѧ����ѧ��:";
    cin>>nid;
    if(h->idfind(nid)){
        shead=shead->next;
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

float shuxuexi::qpingjun(){
     float n=0,m=0;
     m=gpingjun()*3;
     n=m+shibian+fanhan+weifen;
     n/=6;
     return n;

}
