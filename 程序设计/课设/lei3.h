#ifndef LEI3_H_INCLUDED
#define LEI3_H_INCLUDED

class jisuanjixi:virtual public student
{
    public:
        jisuanjixi(){}
        jisuanjixi(int i);
        void show();
        class jisuanjixi *next;
        void chaxun(class jisuanjixi *jhead);
        void add(class jisuanjixi *jhead);
        void shanchu(class jisuanjixi *jhead);
         float qpingjun();
   private:
    float zucheng;
    float tixi;
    float huibian;
};

class jisuanjixi* jisuanjix(){


	int n=0,len,m=1;
	cout<<"请输入学生人数"<<endl;
	cin>>len;
    class jisuanjixi *c,*h,*pre;
    while(len){
            cout<<setw(20)<<"请输入第"<<m<<"个人信息"<<endl;
             ++m;
            c=new jisuanjixi(0);
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
class jisuanjixi * jpaixu(class jisuanjixi *jhead){
     int i,j,len=0;
     float cg1,cg2;
     class jisuanjixi *p,*q,*tmp,*h;
     class jisuanjixi *subhead;
	 class jisuanjixi *pre,*nhead;
	 pre=new jisuanjixi;
	 pre->next=jhead;
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
	   jhead=pre->next;
	   delete pre;
	   h=jhead;
	   return h;
}


class jisuanjixi * jqpaixu(class jisuanjixi *jhead){
     int i,j,len=0;
     float cg1,cg2;
     class jisuanjixi *p,*q,*tmp,*h;
     class jisuanjixi *subhead;
	 class jisuanjixi *pre,*nhead;
	 pre=new jisuanjixi;
	 pre->next=jhead;
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
	   jhead=pre->next;
	   delete pre;
	   h=jhead;
	   return h;
}
#endif // LEI3_H_INCLUDED
