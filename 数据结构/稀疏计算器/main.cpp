#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
struct poly{
  float c;
  string x;
  int e;
  struct poly *next;
};
struct poly *creater(int len){
    int n=0;
    struct poly *p,*h,*pre;
    while(n<len){
        p=new poly;
        if(n==0){
            h=p;
            pre=p;
        }
        else{
           pre->next=p;
            pre=p;
        }
        ++n;
        p->next=NULL;
        cout<<"input di "<<n<<" ge:";
        cin>>p->c;
        cin>>p->x;
        cin>>p->e;
    }
    return h;
}
void input(struct poly *pre){
     static int num=0;
     while(pre!=NULL){
            if(pre->c==0)continue;
            if(pre->e==0){
                    if(num==0)cout<<pre->c;
                    else{
                       if(pre->c<0)cout<<pre->c;
                        else{cout<<"+"<<pre->c;}
                  }
            }
            if(pre->e==1){
                   if(num==0)cout<<pre->c<<pre->x;
                    else{
                       if(pre->c<0)cout<<pre->c<<pre->x;
                        else{cout<<"+"<<pre->c<<pre->x;}
                  }
            }
            if(pre->e!=0&&pre->e!=1){
                   if(num==0)cout<<pre->c<<pre->x<<pre->e;
                    else{
                       if(pre->c<0)cout<<pre->c<<pre->x<<pre->e;
                        else{cout<<"+"<<pre->c<<pre->x<<pre->e;}
                  }
            }
        pre=pre->next;
        num=num+1;
    }



}

void free(struct poly *h){
    struct poly *a,*p;
  while(a!=NULL)
    {
        p=a->next;
        delete a;
        a=p;
    }

}
void jisuan(struct poly *a,struct poly *b,int n)
{
    int num,result;
    struct poly *p,*h,*pre,*z,*y;
    z=a->next;
    y=b->next;
     while(z!=NULL){
        p=new poly;
        num=z->e;
        while(y!=NULL&&num!=y->e)y=y->next;
        result=z->c;
       if(y!=NULL){
            if(num==(y->e)){
             if(n==1){
                    result=z->c+y->c;
             }
             if(n==2){
                result=z->c-y->c;
             }
              pre=b;
             while((pre->next)->e!=y->e){
              pre=pre->next;
              cout<<"HVJG"<<endl;
               }
             pre->next=y->next;
             delete y;
        }
       }
        y=b->next;
        p->c=result;
        p->x=z->x;
        p->e=z->e;
        z=z->next;
        input(p);
        delete p;

    }
    p=b->next;
    if(p!=NULL){
        input(p);
        p=p->next;
    }
}



int main()
{
    char tmp;
    int n=0,num=0;
    struct poly *a,*p,*b,*pre;
    cout<<"please input A length:";
    cin>>n;
    a=new poly;
    a->next=creater(n);
    cout<<"please input B length:";
    cin>>n;
    b=new poly;
    b->next=creater(n);
    cout<<"1,a+b     2,a-b"<<endl;
    cin>>num;
    jisuan(a,b,num);
    free(a);
    free(b);
}
