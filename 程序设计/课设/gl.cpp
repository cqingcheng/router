#include <iostream>
#include "guanli.h"
#include "lei1.h"
#include "lei2.h"
#include "lei3.h"

using namespace std;
class yingyuxi* yingyux(){
	int n=0,len,m=1;
	float zhyy,ku;
    cout<<"请输入学生人数"<<endl;
    cin>>len;
    class yingyuxi *c,*h,*pre;
    while(len){
             cout<<setw(20)<<"请输入第"<<m<<"个人信息"<<endl;
             ++m;
             cout<<"请输入综合英语成绩：";
             cin>>zhyy;
             cout<<"请输入口语成绩：";
             cin>>ku;
             c=new yingyuxi(zhyy,ku);
              if(n==0){
             h=c;
             pre=c;
             ++n;
        }
        else{
           pre->next=c;
            pre=c;
        }
       c->next=NULL;
        --len;
    }
     return h;
}

class yingyuxi * ypaixu(class yingyuxi *yhead){
     int i,j,len=0;
     float cg1,cg2;
     class yingyuxi *p,*q,*tmp,*h;
     class yingyuxi *subhead;
	 class yingyuxi *pre,*nhead;
	 pre=new yingyuxi;
	 pre->next=yhead;
     h=pre;
     while(h!=NULL){
     ++len;
     h=h->next;
	 }
	 if(len<=1);
	 else{
     for(i=0;i<len-1;++i){
   	     subhead=pre;
   	     p=pre->next;
	     q=p->next;
	     for(j=0;j<len-2-i;++j){
                cg1=p->gpingjun();
                cg2=q->gpingjun();
	    	if(cg1<cg2){
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
      }
	   yhead=pre->next;
	  delete pre;
      h=yhead;
      return h;

}

class yingyuxi * yqpaixu(class yingyuxi *yhead){
     int i,j,len=0;
     float cg1,cg2;
     class yingyuxi *p,*q,*tmp,*h;
     class yingyuxi *subhead;
	 class yingyuxi *pre,*nhead;
	 pre=new yingyuxi;
	 pre->next=yhead;
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
                cg1=p->qpingjun();
                cg2=q->qpingjun();
	    	if(cg1<cg2){
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
	   yhead=pre->next;
	  delete pre;
	  h=yhead;
	  return h;
}




void Guanli::Guanliluru(){
    int n=0,m=1;
    yhead=NULL;
    shead=NULL;
    jhead=NULL;
    while(m){
    cout<<"                 请选择输出学生的院系"<<endl;
    cout<<"          1.英语系 2.数学系 3.计算机系"<<endl;
    cin>>n;
    if(n==1){ yhead=yingyux();}
    if(n==2){shead=shuxuex();}
    if(n==3){jhead=jisuanjix();}
    cout<<endl;
    cout<<"                继续输入 1、是  2、否"<<endl;
    cin>>m;
    if(m==2)m=0;
 }
}

void Guanli::show(){
    class yingyuxi *h;
    h=yhead;
      while(h!=NULL){
         h->show();
         h=h->next;
      }

    class shuxuexi *n;
    n=shead;
      while(n!=NULL){
         n->show();
         n=n->next;
      }
    class jisuanjixi *m;
    m=jhead;
    while(m!=NULL){
         m->show();
         m=m->next;
      }




}

void Guanli::chanxue(){
    int n=0;
    cout<<"请选择查询学生的院系"<<endl;
    cout<<"1.英语系 2.数学系 3.计算机系"<<endl;
    cin>>n;
    if(n==1){yhead->chaxun(yhead);}
    if(n==2){shead->chaxun(shead);}
    if(n==3){jhead->chaxun(jhead);}

}

void Guanli::add1(){
   int n=0;
   cout<<"1.英语系   2.数学系     3.计算机系"<<endl;
   cout<<"请选择增加学生的院系：";
   cin>>n;
   while(n<1||n>3){
     cout<<"输入错误，请重新输入"<<endl;
      cin>>n;
   }
   if(n==1){yhead->add(yhead);}
   if(n==2){shead->add(shead);}
   if(n==3){jhead->add(jhead);}
}

void Guanli::shanchuxs(){
     int n=0;
    cout<<"请选择删除学生的院系"<<endl;
    cout<<"1.英语系 2.数学系 3.计算机系"<<endl;
    cin>>n;
    if(n==1){ yhead->shanchu(yhead);}
    if(n==2){shead->shanchu(shead);}
    if(n==3){jhead->shanchu(jhead);}
}

void Guanli::gpx(){
     yhead=ypaixu(yhead);
     shead=spaixu(shead);
     jhead=jpaixu(jhead);
     class yingyuxi *yh=yhead;
     class shuxuexi *sh=shead;
     class jisuanjixi *jh=jhead;
     float yg=0,sg=0,jg=0;
     while(yh!=NULL||sh!=NULL||jh!=NULL){
              if(yh==NULL){yg=-1;}
              else{yg=yh->gpingjun();}
              if(sh==NULL){sg=-1;}
              else{sg=sh->gpingjun();}
              if(jh==NULL){jg=-1;}
              else{jg=jh->gpingjun();}
              if(yg>sg&yg>jg){
                yh->show();
                yh=yh->next;
              }
              if(sg>yg&&sg>jg){
                sh->show();
                sh=sh->next;
              }
              if(jg>yg&&jg>sg){
                jh->show();
                jh=jh->next;
              }
              if(jg==yg&&jg==sg){
                yh->show();
                yh=yh->next;
                sh->show();
                sh=sh->next;
                jh->show();
                jh=jh->next;
              }
     }

}

void Guanli::qpx(){
     yhead=yqpaixu(yhead);
     shead=sqpaixu(shead);
     jhead=jqpaixu(jhead);
     class yingyuxi *yh=yhead;
     class shuxuexi *sh=shead;
     class jisuanjixi *jh=jhead;
     float yg=0,sg=0,jg=0;
     while(yh!=NULL||sh!=NULL||jh!=NULL){
             if(yh==NULL){yg=-1;}
              else{yg=yh->qpingjun();}
              if(sh==NULL){sg=-1;}
              else{sg=sh->qpingjun();}
              if(jh==NULL){jg=-1;}
              else{jg=jh->qpingjun();}
              if(yg>sg&yg>jg){
                yh->show();
                yh=yh->next;
              }
              if(sg>yg&&sg>jg){
                sh->show();
                sh=sh->next;
              }
              if(jg>yg&&jg>sg){
                jh->show();
                jh=jh->next;
              }
              if(jg==yg&&jg==sg){
                yh->show();
                yh=yh->next;
                sh->show();
                sh=sh->next;
                jh->show();
                jh=jh->next;
              }
     }
}

int  Guanli::Guanlisc(){
     class yingyuxi *y;
     while(yhead!=NULL){
		y=yhead->next;
		delete yhead;
		yhead=y;
	}
    class shuxuexi *s;
    while(shead!=NULL){
		s=shead->next;
		delete shead;
		shead=s;
	}
    class jisuanjixi *j;
    while(jhead!=NULL){
		j=jhead->next;
		delete jhead;
		jhead=j;
	}
   return 0;
}

