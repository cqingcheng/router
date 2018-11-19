#ifndef LEI2_H_INCLUDED
#define LEI2_H_INCLUDED

class shuxuexi:virtual public student
{
    public:
        shuxuexi(){}
     shuxuexi(float sbhs,float fhfx,float wfjh):shibian(sbhs),fanhan(fhfx),weifen(wfjh),student(2){}
     void show();
     class shuxuexi *next;
    void chaxun(class shuxuexi *shead);
    void add(class shuxuexi *shead);
    void shanchu(shuxuexi *shead);
     float qpingjun();
   private:
    float shibian;
    float fanhan;
    float weifen;
};

class shuxuexi* shuxuex(){
	int n=0,len,m=1;
	float sbhs,fhfx,wfjh;
	cout<<"请输入学生人数"<<endl;
	cin>>len;
    class shuxuexi *c,*h,*pre;

    while(len){
             cout<<setw(20)<<"请输入第"<<m<<"个人信息"<<endl;
             ++m;
             cout<<"请输入实变函数的成绩:";
             cin>>sbhs;
             cout<<"请输入泛函分析的成绩:";
             cin>>fhfx;
             cout<<"请输入微分几何的成绩:";
             cin>>wfjh;
            c=new shuxuexi(sbhs,fhfx,wfjh);
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

class shuxuexi * spaixu(class shuxuexi *shead){
     int i,j,len=0;
     float cg1,cg2;
     class shuxuexi *p,*q,*tmp,*h;
     class shuxuexi *subhead;
	 class shuxuexi *pre,*nhead;
	 pre=new shuxuexi;
	 pre->next=shead;
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
	   shead=pre->next;
	  delete pre;
	  h=shead;
	  return h;
}



class shuxuexi * sqpaixu(class shuxuexi *shead){
     int i,j,len=0;
     float cg1,cg2;
     class shuxuexi *p,*q,*tmp,*h;
     class shuxuexi *subhead;
	 class shuxuexi *pre,*nhead;
	 pre=new shuxuexi;
	 pre->next=shead;
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
	   shead=pre->next;
	  delete pre;
	  h=shead;
	  return h;
}
#endif // LEI2_H_INCLUDED
