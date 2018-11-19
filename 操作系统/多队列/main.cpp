#include <iostream>
#include <fstream>
#include<iomanip>

using namespace std;

 typedef  struct  tag_pcb
    {  string  name;
       int need;
       int turn;
       struct  tag_pcb  *next;
   } PCB;
PCB *RQ1,*RQ2,*Finish;
int clock=0;
int q=7;
PCB* creater(){
     ifstream ifile;
	 ifile.open("jincheng.txt");
	PCB *c,*h,*pre;
	int n=5;
    string name1;
    int need1,turn1;

	while(n){
        c=new PCB;
        if(n==5){
            h=c;
            pre=c;
        }
        else{
           pre->next=c;
            pre=c;
        }
       ifile>>c->name>>c->need>>c->turn;
       c->next=NULL;
      if(ifile.eof()!=0) {break;}
      --n;
    }
     ifile.close();
     return h;
}
PCB* creater1(){
   ifstream ifile;
	 ifile.open("jincheng1.txt");
	PCB *c,*h,*pre;
	int n=5;
    string name1;
    int need1,turn1;

	while(n){
        c=new PCB;
        if(n==5){
            h=c;
            pre=c;
        }
        else{
           pre->next=c;
            pre=c;
        }
       ifile>>c->name>>c->need>>c->turn;
       c->next=NULL;
      if(ifile.eof()!=0) {break;}
      --n;
    }
     ifile.close();
     return h;
}
void zhouzhuan(PCB *b,int q){
    while(b!=NULL){
        (b->turn)=q+(b->turn);
        b=b->next;
    }
}
int lunzhuan(PCB* a){
   PCB *pre,*h,*tmp,*ls;
   int t,time=0;
   pre=a;
   h=a;
   while(pre!=NULL){
       tmp=pre;
       ls=pre;
       t=0;
      if((pre->need)>q){
            time+=q;
          pre->need-=q;
        zhouzhuan(tmp,q);
        pre=pre->next;
        while(h->next!=NULL){
            h=h->next;
        }
        h->next=tmp;
        tmp->next=NULL;
        continue;
      }
      if(pre->need<=q){
          time+=pre->need;
        zhouzhuan(pre,pre->need);

        cout<<pre->name<<"           "<<pre->turn<<endl;
         pre->need=0;
         ls=pre;
        pre=pre->next;
        delete ls;
        continue;
      }
   }
   return time;
}


void duan(PCB *b){
    int i,j,len=0,mg1,mg2;
     PCB *p,*q,*tmp,*h,*head;
     PCB *subhead;
	 PCB *pre,*nhead;
	 pre=new PCB;
	 pre->next=b;
     h=pre;
     while(h!=NULL){
     ++len;
     h=h->next;
	 }

     for(i=0;i<len-1;++i){
   	     subhead=pre;
   	     p=pre->next;
	     q=p->next;
	     for(j=0;j<len-2-i;++j){
                mg1=p->need;
                mg2=q->need;
	    	if(mg1>mg2){
		        subhead->next=p->next;
    	    	p->next=q->next;
	        	q->next=p;
         		tmp=p;
    	    	p=q;
	    	    q=tmp;
			}
	     subhead=subhead->next;
	   	 p=p->next;
		 q=q->next;
		 }
   }
    head=pre->next;
    h=pre->next;
    delete pre;
   while(h!=NULL){
        b=h;
       zhouzhuan(b,h->need);
       cout<<h->name<<"           "<<h->turn<<endl;
       h=h->next;
        delete b;
   }
}


int main ( )
{
   int t;
   PCB *pre;
   RQ1=creater();
   RQ2=creater1();
   cout<<"done        turn time"<<endl;
   t=lunzhuan(RQ1);
   pre=RQ2;
   zhouzhuan(pre,t);
   duan(RQ2);
   int pause;cin>>pause;
}
