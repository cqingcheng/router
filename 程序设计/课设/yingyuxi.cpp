#include <iostream>
#include "lei1.h"

using namespace std;

yingyuxi::yingyuxi(float zhyy,float ku):student(1){
    zongheyingyu=zhyy;
   kouyu=ku;
}
void yingyuxi::show(){
    show1();
    cout<<"       �ۺ�Ӣ��ɼ���"<<zongheyingyu;
    cout<<"       ����ɼ�"<<kouyu<<endl;

}
void yingyuxi::chaxun(class yingyuxi *yhead){
    class yingyuxi *h;
    h=yhead;
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

void yingyuxi::add(class yingyuxi *yhead){
   class yingyuxi*h,*c;
   float zhyy,ku;
   cout<<"�������ۺ�Ӣ��ɼ���";
    cin>>zhyy;
    cout<<"���������ɼ���";
    cin>>ku;
    c=new yingyuxi(zhyy,ku);
   h=yhead;
   while((h->next)!=NULL){h=h->next;}
   h->next=c;
   c->next=NULL;
}

void yingyuxi::shanchu(class yingyuxi *yhead){
    int nid;
    class yingyuxi *h,*pre;
    h=yhead;
    cout<<"������ɾ��ѧ����ѧ��:";
    cin>>nid;
    if(h->idfind(nid)){
        yhead=yhead->next;
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

float yingyuxi::qpingjun(){
     float n=0,m=0;
     m=gpingjun()*3;
     n=m+zongheyingyu+kouyu;
     n/=5;
     return n;
}
