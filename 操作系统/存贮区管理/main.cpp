#include<iostream>
#include<fstream>
#include<cstdlib>
#define maxsize 512
using namespace std;

typedef struct block
{
    int flag;
    int size;
    struct block *next;
}rd;
rd *me=new rd[maxsize];   //存储空间
rd *Freeq,*J[10],*request;

int read(ifstream &out)//读取
{
    int num;
    if(!out)
        return -1;
    out>>num;
    if(out.eof())
        return -1;
    else
    {
        char oper;
        out>>oper;
        if(oper=='S')
        {
            request->flag=1;
            out>>request->size;
            cout<<"process "<<num<<"   apply "<<request->size<<endl;
        }
        else
        {
            request->flag=0;
            cout<<"process "<<num<<"        end"<<endl;

        }
    }
    return num;
}
void print()//输出
{
    rd *current=Freeq->next;
    while(current!=NULL)
    {
        cout<<"                      relative address:"<<(current-me)<<"             size:"<<current->size<<endl;
        current=current->next;
    }
}


void paixu(rd* current,int num)  //调整队列
{
    rd *temp=Freeq;
    rd *pre=Freeq;
    while(pre->next!=current)
        pre=pre->next;
    pre->next=pre->next->next;
    while(temp->next!=NULL)
    {
        if(num==1){
            if(temp->next->size>current->size){
            current->next=temp->next;
            temp->next=current;
            return;
             }
        }
        if(num==2){
            if(temp->next->size<=current->size){
            current->next=temp->next;
            temp->next=current;
            return;
        }
        }
        temp=temp->next;
    }
    temp->next=current;
    current->next=NULL;
}
void Request(int num,int a)//申请
{
    rd *temp=Freeq;
    while(temp->next!=NULL)
    {
        if(temp->next->size>request->size)
        {

            if(temp->next->size==request->size+1)
            {
                temp->next->flag=1;
                J[num]=temp->next->next;
                temp->next=temp->next->next;
                return;
            }
            else
            {
                temp->next->size=temp->next->size-request->size-1;
                (temp->next+temp->next->size)->flag=1;
                (temp->next+temp->next->size)->size=request->size+1;
                J[num]=(temp->next+temp->next->size+1);
                if(a==1)paixu(temp->next,1);
                if(a==2)paixu(temp->next,2);
                return;
            }
        }
        else
            temp=temp->next;
    }
}
void Release(int num,int o)//释放
{
    rd *m,*n,*pre,*temp,*r=J[num]-1;
    J[num]=NULL;
    if(o==2){m=me;}
    else{m=Freeq->next;}
    n=r+r->size;
    while((m+m->size)!=r)
        {m+=m->size;}
    if(m->flag==0&&n->flag==0)//m空闲，n空闲
    {
        if(o==0||o==1){
            m->size=m->size+r->size+n->size;
            m->next=n->next;
            if(o==1)paixu(m,1);
        }
       if(o==2){
           temp=Freeq;
           while(temp!=n)
           {
              if(temp->next==n)
                  pre=temp;
                  temp=temp->next;
          }
          pre->next=pre->next->next;
          m->size=m->size+r->size+n->size;
          paixu(m,2);
       }
    }
    if(m->flag==0&&n->flag!=0)  //m空闲，n已分配
    {
        m->size=m->size+r->size;
        if(o==1)paixu(m,1);
        if(o==2)paixu(m,2);
    }
    if(m->flag!=0&&n->flag==0)  //m已分配，n空闲
    {
        if(o==1||o==0){
            temp=Freeq->next;
            while(temp+temp->size!=r)
           {
                if(temp->flag==0)
                   pre=temp;
                  temp+=temp->size;
           }
        }
        if(o==2){
            temp=Freeq;
            while(temp!=n)
           {
                if(temp->next==n)
                   pre=temp;
                  temp=temp->next;
           }
        }
        r->size=r->size+n->size;
        r->flag=0;
        r->next=n->next;
        pre->next=r;
        n->size=0;
        if(o==1)paixu(r,1);
        if(o==2)paixu(r,2);
        return;
    }
    if(m->flag!=0&&n->flag!=0)  //m已分配，n已分配
    {

        if(o==1||o==0)temp=Freeq->next;
        if(o==2){temp=me;}
        while(temp+temp->size!=r)
        {
            if(temp->flag==0)
                pre=temp;
                temp+=temp->size;
        }
        r->next=pre->next;
        pre->next=r;
        r->flag=0;
        if(o==1)paixu(r,1);
        if(o==2)paixu(r,2);
        return;
    }
    r->flag=0;
    r->size=0;
    r->next=NULL;
}


void first(ifstream &in)//首次适应算法
{
    int num;
    while(1)
    {
        num=read(in);
        if(num==-1)
            return;
        if(request->flag==1)
            Request(num,0);
        else
            Release(num,0);
        print();
    }
}
void best(ifstream &in)//最佳适应算法
{
    int num;
    while(1)
    {
        num=read(in);
        if(num==-1)
            return;
        if(request->flag==1)
            Request(num,1);
        else
            Release(num,1);
        print();
    }
}
void worse(ifstream &in)//最坏适应算法
{
    int num;
    while(1)
    {
        num=read(in);
        if(num==-1)
            return;
        if(request->flag==1)
            Request(num,2);
        else
            Release(num,2);
        print();
    }
}


int main()
{
    int n=0;
    while(n!=4){
        Freeq = new rd;
        request =new rd;
        Freeq -> flag = -1;
        Freeq -> next = me;
        me -> flag = 0;
        me -> size = maxsize;
        me -> next = NULL;
        ifstream in("shuju.txt");
        if(!in)
        {
        cerr << "wrong" << endl;
        exit(1);
        }
        cout<<"           ****************************************************************************************************"<<endl;
        cout<<"                                                    1.First fit"<<endl;
        cout<<"                                                    2.best fit"<<endl;
	    cout<<"                                                    3.worse fit"<<endl;
	    cout<<"                                                    4.exit"<<endl;
	    cout<<"           ****************************************************************************************************"<<endl;
        cin>>n;
        if(n==1){cout<<"First fit"<<endl;first(in);}
        if(n==2){cout<<"best fit"<<endl;best(in);}
        if(n==3){cout<<"worse fit"<<endl;worse(in);}
        in.close();
    }
}

