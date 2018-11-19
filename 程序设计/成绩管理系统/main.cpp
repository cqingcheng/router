// 文本目录.cpp : Defines the entry point for the console application.
#include <iostream>
#include <fstream>
#include<iomanip>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class chengji
{
public:
    class chengji* next;
    void input();
    void _tranvale();
    int cunchu(class chengji *head);
    int xunzhaoid(int fid);
    int xunzhaoname(string fname);
    float fanhuiyuwen(){return chinesegrade;}
    float fanhuishuxue(){return mathgrade;}
    float fanhuiyingyu(){return englishgrade;}
    void fuzhi(string name1,int id1,float c,float m,float e){
     name=name1;id=id1,chinesegrade=c,mathgrade=m,englishgrade=e;
    }
private:
    string name;
    int id;
    float chinesegrade;
    float mathgrade;
    float englishgrade;

};
int chengji::xunzhaoid(int fid){
    if(fid==id){return 1;}
    else{
        return 0;
    }
}
int chengji::xunzhaoname(string fname){
    if(fname==name)return 1;
    else{
        return 0;
    }
}
void chengji::input(){
    string _name;
    cout<<"  请输入名字:";
    cin>>_name;
    name=_name;
    int _id;
    cout<<"  请输入学号:";
    cin>>_id;
    id=_id;
    float _chinesegrade;
    cout<<"  请输入语文成绩:";
    cin>>_chinesegrade;
    chinesegrade=_chinesegrade;
    float _mathgrade;
    cout<<"  请输入数学成绩:";
    cin>>_mathgrade;
    mathgrade=_mathgrade;
    float _englishgrade;
    cout<<"  请输入英语成绩:";
    cin>>_englishgrade;
    englishgrade=_englishgrade;
}
void chengji::_tranvale(){
    cout<<"姓名:  "<<name<<"        id: "<<id<<"      语文成绩: "<<chinesegrade<<"       数学成绩: "<<mathgrade<<"      英语成绩: "<<englishgrade<<endl;
}
int chengji::cunchu(class chengji *head){
    ofstream chengji;
    chengji.open("D:\\c++\\程序设计\\成绩管理系统\\chengjiguanlixitong.txt",ios::out);
    if(chengji==NULL){
            cout<<"此文件打不开";
            return -1;
	}
    while(head->next!=NULL){
        chengji<<head->name<<setw(6)<<head->id<<setw(6)<<head->chinesegrade<<setw(6)<<head->mathgrade<<setw(6)<<head->englishgrade<<endl;
        cout<<"dgsdfg"<<head->name<<setw(6)<<head->id<<setw(6)<<head->chinesegrade<<setw(6)<<head->mathgrade<<setw(6)<<head->englishgrade<<endl;
        head=head->next;
    }
    chengji<<head->name<<setw(6)<<head->id<<setw(6)<<head->chinesegrade<<setw(6)<<head->mathgrade<<setw(6)<<head->englishgrade;
    chengji.close();
    return 0;
}
class chengji* read(){
	 ifstream ifile;
	 ifile.open("D:\\c++\\程序设计\\成绩管理系统\\chengjiguanlixitong.txt");
	class chengji *c,*h,*pre;
	int n=0;
    string name1;
    int id1;
    float d,m,e;
    if(ifile==NULL){
            cout<<"                                   此文件打不开";
            return NULL;
	}
	while(1){
        c=new chengji;
        if(n==0){
            h=c;
            pre=c;
        }
        else{
           pre->next=c;
            pre=c;
        }
       ifile>>name1>>id1>>d>>m>>e;
        c->fuzhi(name1,id1,d,m,e);
        c->next=NULL;
      if(ifile.eof()!=0) {break;}
        ++n;
    }
     ifile.close();
     return h;
}
class chengji *creater(int len){
    int n=0;
    class chengji *c,*h,*pre;
    while(n<len){
        c=new chengji;
        if(n==0){
            h=c;
            pre=c;
        }
        else{
           pre->next=c;
            pre=c;
        }
        c->next=NULL;
        c->input();
        ++n;
    }

    return h;

}
void releas(class chengji*head){
    class chengji*n;
	while(head!=NULL){
		n=head->next;
		delete head;
		head=n;

	}
}
void tranvest(class chengji*head){
     while(head!=NULL){
        head->_tranvale();
		head=head->next;

	}
}
void catalog(class chengji*head);
void catalog1(class chengji*head);
void catalog2(class chengji*head);
void catalog3(class chengji*head);
void mulu(){
cout<<endl;
   cout<<endl;
   cout<<"--------------------------------------学生成绩管理系统-----------------------------------------"<<endl;
   cout<<"                                       1.信息维护"<<endl;
   cout<<"                                       2.信息查询"<<endl;
   cout<<"                                       3.成绩统计"<<endl;
   cout<<"                                       4.成绩排序"<<endl;
   cout<<"                                       5.成绩目录"<<endl;
   cout<<"                                       6.退出系统"<<endl;
   cout<<"------------------------------------------------------------------------------------------------"<<endl;
   cout<<endl;
   cout<<endl;

}
void add(class chengji*head){//增加信息
	class chengji* p,*counter,*h;
    p=new chengji;
    p->input();
	p->next=NULL;
	h=head;
    while(h->next!=NULL){
		h=h->next;
		}
        h->next=p;
    head->cunchu(head);
    tranvest(head);
    Sleep(4000);
	catalog(head);
}
void deletion(class chengji*head){//删除信息
	int did=-1;
	class chengji *cut,*pre;
    int nid;
	pre=head;
	cut=head;
	cout<<"                                   请输入被删除学生的学号:";
	while(did<0){
        cin.sync();
        cin>>did;
	}
	 if(cut->xunzhaoid(did)){
        head=head->next;
		delete cut;
	 }
	 else{
            while(cut!=NULL){
                pre=cut;
                cut=cut->next;
                if(cut->xunzhaoid(did)){
                    pre->next=cut->next;
                    delete cut;
                    break;
           }
	   }
	}
	pre=pre->next;
	cout<<"已删除学号为"<<did<<"学生信息"<<endl;
    tranvest(head);
    head->cunchu(head);
    Sleep(4000);
	catalog(head);
}
void change(class chengji*head){//修改信息
    int n=0,d=0,e=0;
	class chengji *h;
	h=head;
    cout<<"                                      1.姓名"<<endl;
	cout<<"                                      2.学号"<<endl;
	cout<<"                                   请选择输入学生信息:";
	cin>>n;
	if(n!=1&&n!=2){cout<<"                        输入错误"<<endl;change(head);}
	if(n==1){
	string fname,nname;
    cout<<"                                   请输入学生姓名:";
	cin>>fname;
	while(h!=NULL){
		if(h->xunzhaoname(fname)){
		   h->input();
		   head->cunchu(head);
		   ++d;
		}
		h=h->next;
	}
	if(d==0){cout<<"                             查无此人"<<endl;}
    cout<<"                              1.继续修改         2.返回主目录"<<endl;
    cin>>e;
    while(e!=1&&e!=2){cout<<"                    重新选择：";cin>>e;}
    if(e==1){change(head);}
    if(e==2){catalog(head);}
	}
	if(n==2){
	    int fid,nid;
		cout<<"                             请输入学生学号:";
		cin>>fid;
	while(h!=NULL){
		if(h->xunzhaoid(fid)){
		   h->input();
		   head->cunchu(head);
           ++d;
		}
		h=h->next;
	}
	if(d==0){cout<<"                             查无此人"<<endl;}
    cout<<"                              1.继续修改         2.返回主目录"<<endl;
    cin>>e;
    while(e!=1&&e!=2){cout<<"                    重新选择：";cin>>e;}
    if(e==1){change(head);}
    if(e==2){Sleep(700);catalog(head);}
	}
}
void namefind(class chengji*head){//名字查找
	string fname,nname;
	int n=0;
    class chengji*h;
	h=head;
    cout<<"                                   请输入学生姓名: ";
	cin>>fname;
	while(h!=NULL){
		if(h->xunzhaoname(fname)){
		   h->_tranvale();
		   ++n;
		}
		h=h->next;
	}
	if(n==0){
	    cout<<"                                   查无此人"<<endl;
	    catalog2(head);
	}
	Sleep(4000);
	catalog(head);
}
void idfind(class chengji*head){//按学号查找
	int fid=-1,nid,n=0;
    class chengji*h;
	h=head;
    cout<<"                                    请输入学生学号: ";
	while(fid<0){
        cin>>fid;
        cin.sync();
	}

	while(h!=NULL){
            if(h->xunzhaoid(fid)){
                h->_tranvale();
                ++n;
            }
		h=h->next;
	}
	if(n==0){
	   cout<<"                                        该学号学生不存在";
	   catalog2(head);
	}
	Sleep(4000);
	catalog(head);
}
//成绩分段统计
void yuwenfenduan(class chengji*head){
    int a=0,b=0,c=0,d=0,e=0;
    float grade=0.0;
	class chengji*h;
	h=head;
	while(h!=NULL){
         grade=h->fanhuiyuwen();
		 if(grade<=100&&grade>90){++a;}
		 if(grade<=90&&grade>80){++b;}
         if(grade<=80&&grade>70){++c;}
		 if(grade<=70&&grade>60){++d;}
		 if(grade<=60){++e;}
    h=h->next;
	}
    cout<<"                                          语文成绩分段统计"<<endl;
	cout<<"                                          (90,100]: "<<a<<endl;
    cout<<"                                          (80,90]:  "<<b<<endl;
	cout<<"                                          (70,80]:  "<<c<<endl;
	cout<<"                                          (60,70]:  "<<d<<endl;
	cout<<"                                          (0,60]:   "<<e<<endl;
	Sleep(4000);
	catalog(head);
}
void shuxuefenduan(class chengji*head){
    int a=0,b=0,c=0,d=0,e=0;
    float grade=0.0;
	class chengji*h;
	h=head;
	while(h!=NULL){
         grade=h->fanhuishuxue();
		 if(grade<=100&&grade>90){++a;}
		 if(grade<=90&&grade>80){++b;}
         if(grade<=80&&grade>70){++c;}
		 if(grade<=70&&grade>60){++d;}
		 if(grade<=60){++e;}
    h=h->next;
	}
    cout<<"                                          数学成绩分段统计"<<endl;
	cout<<"                                          (90,100]: "<<a<<endl;
    cout<<"                                          (80,90]:  "<<b<<endl;
	cout<<"                                          (70,80]:  "<<c<<endl;
	cout<<"                                          (60,70]:  "<<d<<endl;
	cout<<"                                          (0,60]:   "<<e<<endl;
	Sleep(4000);
	catalog(head);
}
void yingyufenduan(class chengji*head){
    int a=0,b=0,c=0,d=0,e=0;
    float grade=0.0;
	class chengji*h;
	h=head;
	while(h!=NULL){
         grade=h->fanhuiyingyu();
		 if(grade<=100&&grade>90){++a;}
		 if(grade<=90&&grade>80){++b;}
         if(grade<=80&&grade>70){++c;}
		 if(grade<=70&&grade>60){++d;}
		 if(grade<=60){++e;}
    h=h->next;
	}
    cout<<"                                          英语成绩分段统计"<<endl;
	cout<<"                                          (90,100]: "<<a<<endl;
    cout<<"                                          (80,90]:  "<<b<<endl;
	cout<<"                                          (70,80]:  "<<c<<endl;
	cout<<"                                          (60,70]:  "<<d<<endl;
	cout<<"                                          (0,60]:   "<<e<<endl;
	Sleep(4000);
	catalog(head);
}
//平均成绩
void yuwenpingjun(class chengji*head){//科目平均
	float sum=0.0,grade=0.0;
	int n=0;
	class chengji*h;
	h=head;
	while(h!=NULL){
            grade=h->fanhuiyuwen();
	        sum+=grade;
	        h=h->next;
            ++n;
	}
	sum=sum/n;
	cout<<"                                    该科目平均成绩:"<<sum<<endl;
	Sleep(4000);
	catalog(head);
}
void shuxuepingjun(class chengji*head){
	float sum=0.0,grade=0.0;
	int n=0;
	class chengji*h;
	h=head;
	while(h!=NULL){
            grade=h->fanhuishuxue();
	        sum+=grade;
	        h=h->next;
            ++n;
	}
	sum=sum/n;
	cout<<"                                     该科目平均成绩:"<<sum<<endl;
	Sleep(4000);
	catalog(head);
}
void yingyupingjun(class chengji*head){
	float sum=0.0,grade=0.0;
	int n=0;
	class chengji*h;
	h=head;
	while(h!=NULL){
            grade=h->fanhuiyingyu();
	        sum+=grade;
	        h=h->next;
            ++n;
	}
	sum=sum/n;
	cout<<"                                       该科目平均成绩:"<<sum<<endl;
	Sleep(4000);
	catalog(head);
}
void studentpignjun(class chengji*head){//个人平均
    int n,fid,nid;
    float grade;
    class chengji*h;
    h=head;
    string fname,nname;
    cout<<"                                      1.姓名"<<endl;
	cout<<"                                      2.学号"<<endl;
	cout<<"                                   请选择输入学生信息:";
	cin>>n;
	if(n!=1&&n!=2){
        cout<<"输入有误，重新输入";
        studentpignjun(head);
	}
	if(n==1){
          cout<<"                             请输入学生姓名: ";
          cin>>fname;
	      while(h!=NULL){
		      if(h->xunzhaoname(fname)){
		          grade=(h->fanhuiyuwen())+(h->fanhuishuxue())+(h->fanhuiyingyu());
		          grade=grade/3;
		          cout<<fname<<" 平均成绩："<<grade;
		          n=0;
		     }
		   h=h->next;
	  }
	       if(n!=0){cout<<"                           查无此人"<<endl;
	            Sleep(200);system("cls");mulu();catalog3(head);}
	}
	if(n==2){
	cout<<"                                   请输入学生学号: ";
          cin>>fid;
	      while(h!=NULL){
		      if(h->xunzhaoid(fid)){
		          grade=(h->fanhuiyuwen())+(h->fanhuishuxue())+(h->fanhuiyingyu());
		          grade=grade/3;
		          cout<<fid<<"号学生平均成绩："<<grade;
		          n=0;
		     }
		   h=h->next;
	  }
	  if(n!=0){cout<<"                                 查无此人";
               Sleep(200);system("cls");mulu();catalog3(head);}
	}
	Sleep(4000);
    catalog(head);
}
//成绩排序
void yuwenpaixu(class chengji *head){
     int i,j,len=0,cg1,cg2;
     class chengji *p,*q,*tmp,*h;
     class chengji *subhead;
	 class chengji *pre,*nhead;
	  pre=new chengji;
	 pre->next=head;
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
                cg1=p->fanhuiyuwen();
                cg2=q->fanhuiyuwen();
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
	   head=pre->next;
      tranvest(head);
      delete pre;
	Sleep(4000);
	catalog(head);
}
void shuxuepaixu(class chengji *head){
     int i,j,len=0,mg1,mg2;
     class chengji *p,*q,*tmp,*h;
     class chengji *subhead;
	 class chengji *pre,*nhead;
	 pre=new chengji;
	 pre->next=head;
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
                mg1=p->fanhuishuxue();
                mg2=q->fanhuishuxue();
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
    tranvest(head);
    delete pre;
    Sleep(4000);
    catalog(head);
}
void yingyupaixu(class chengji *head){
     int i,j,len=0,eg1,eg2;
     class chengji *p,*q,*tmp,*h;
     class chengji *subhead;
	 class chengji *pre,*nhead;
	 pre=new chengji;
	 pre->next=head;
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
                eg1=p->fanhuiyingyu();
                eg2=q->fanhuiyingyu();
	    	if(eg1>eg2){
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
      tranvest(head);
	  delete pre;
	Sleep(2000);
	catalog(head);
}
void xueke(){
    cout<<"                              1.语文"<<endl;
	cout<<"                              2.数学"<<endl;
	cout<<"                              3.英语"<<endl;
}
//分段查询目录
void subject1(class chengji*head){
	int n;
	xueke();
	cout<<"                         请输入选择的学科:";
	cin>>n;
	if(n==1){yuwenfenduan(head);}
    if(n==2){shuxuefenduan(head);}
    if(n==3){yingyufenduan(head);}
    if(n<1||n>3){system("cls");mulu();subject1(head);}
}
//平均成绩目录
void subject2(class chengji*head){
	int n=0;
	xueke();
	cout<<"                         请输入选择的学科:";
	cin>>n;
    if(n==1){yuwenpingjun(head);}
    if(n==2){shuxuepingjun(head);}
    if(n==3){yingyupingjun(head);}
    if(n<1||n>3){system("cls");mulu();subject2(head);}
}
//信息维护目录
void mulu1(){
    cout<<"                              1.增加学生信息"<<endl;
	cout<<"                              2.删除学生信息"<<endl;
	cout<<"                              3.修改学生信息"<<endl;
    cout<<"                              4.返回目录"<<endl;
}
void catalog1(class chengji*head){
	int n=0;
	mulu1();
	  cout<<"                         请输入你要进行的操作:";
	  cin>>n;
    if(n==1){add(head);}
    if(n==2){deletion(head);}
    if(n==3){change(head);}
    if(n==4){system("cls");catalog(head);}
    if(n<1||n>4){system("cls");mulu();catalog1(head);}

}
//信息查找目录
void mulu2(){
    cout<<"                              1.按姓名查询"<<endl;
	cout<<"                              2.按学号查询"<<endl;
	cout<<"                              3.返回目录"<<endl;
}
void catalog2(class chengji*head){
	int n=0;
    mulu2();
	cout<<"                         请输入你要进行的操作";
	cin>>n;
    if(n==1){namefind(head);}
    if(n==2){idfind(head);}
    if(n==3){system("cls");catalog(head);}
    if(n<1||n>3){system("cls");mulu();catalog2(head);}


}
//成绩统计目录
void mulu3(){
     cout<<"                              1.分段查询"<<endl;
	 cout<<"                              2.学科平均成绩"<<endl;
	 cout<<"                              3.个人平均成绩"<<endl;
	 cout<<"                              4.返回目录"<<endl;
}
void catalog3(class chengji*head){
     int n=0;
     mulu3();
	 cout<<"                         请输入你要进行的操作:";
	 cin>>n;
     if(n==1){subject1(head);}
     if(n==2){subject2(head);}
     if(n==3){studentpignjun(head);}
     if(n==4){system("cls");catalog(head);}
     if(n<1||n>4){system("cls");mulu();catalog3(head);}
}
//成绩排序目录
void mulu4(){
      cout<<"                              1.按语文成绩排序"<<endl;
      cout<<"                              2.按数学成绩排序"<<endl;
	  cout<<"                              3.按英语成绩排序"<<endl;
	  cout<<"                              4.返回目录"<<endl;
}
void catalog4(class chengji*head){
      int n=0;
	  mulu4();
	  cout<<"                         请输入你要进行的操作:";
	  cin>>n;
      if(n==1){yuwenpaixu(head);}
      if(n==2){shuxuepaixu(head);}
      if(n==3){yingyupaixu(head);}
      if(n==4){system("cls");catalog(head);}
      if(n<1||n>4){system("cls");mulu();catalog4(head);}

}
void stop(class chengji*head){
    releas(head);
	cout<<"按任意键退出";
   exit(-1);
}
//主目录
void catalog(class chengji*head){
   int n=0;
   system("cls");
   mulu();
   cout<<"                         请输入你要进行的操作:";
   cin>>n;
  if(n<1||n>6){
	   system("cls");
	   catalog(head);
	}
   else{
	    if(n==1){catalog1(head);}
	    if(n==2){catalog2(head);}
		if(n==3){catalog3(head);}
		if(n==4){catalog4(head);}
		if(n==5){tranvest(head);Sleep(4000);catalog(head);}
		if(n==6)stop(head);
   }
}
int main()
{
   class chengji *head;
   head=read();
   catalog(head);
   releas(head);
}










/*


void catalog(struct person*);
int save(struct person *);
//定义结构体
struct person{
	char name[10];
	int id;
	int chinesegrade;
	int mathgrade;
	int englishgrade;
	struct  person *next;
};
void input(struct person*,int );
//建立链表
struct person* creater(int len){
	int n=0;
	struct person *c,*h,*pre;
	while(n<len){
		c=(struct person*)malloc(sizeof(struct person));

		if(n==0){
			h=c;
			pre=c;
		}else{
			pre->next=c;
			pre=c;
		}
		c->next= NULL;
		input(c,n);
        ++n;
	}
	return h;
}
//初始化
void input(struct person*p,int num){
    printf("name:");
	scanf("%s",p->name);
    printf("id:");
	scanf("%d",&p->id);
	printf("grade of chinese:");
	scanf("%d",&p->chinesegrade);
	printf("grade of math:");
	scanf("%d",&p->mathgrade);
	printf("grade of english:");
	scanf("%d",&p->englishgrade);
}
//遍历
void tranvest(struct person*head){
     while(head!=NULL){

		printf("姓名:%s\t",head->name);
		printf("学号:%d\t",head->id);
		printf("语文成绩:%d\t",head->chinesegrade);
		printf("数学成绩:%d\t",head->mathgrade);
		printf("英语成绩:%d\n",head->englishgrade);
		head=head->next;
	}
}
//释放
void releas(struct person*head){
    struct person*n;
	while(head!=NULL){
		n=head->next;
		free(head);
		head=n;
	}
}
//增加信息
void add(struct person*head){
	struct person* p,*counter,*h;
    p=(struct person*)malloc(sizeof(struct person));
    input(p,0);
	p->next=NULL;
	h=head;
    while(h!=NULL){
		counter=h;
		h=h->next;
		}
        counter->next=p;
	tranvest(head);
    save(head);
	catalog(head);
}
//删除信息
void deletion(struct person *head){
	int did=0;
	struct person *cut,*pre;

	pre=head;
	cut=head;
	printf("请输入被删除学生的学号:");
	while(!scanf("%d",&did)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
	if(cut->id==did){
	    head=head->next;
		free(cut);
	}
	else{
	   while(cut->id!=did){
           pre=cut;
		   cut=cut->next;
	   }

	   pre->next=cut->next;
       free(cut);
	}
	pre=pre->next;
	printf("已删除学号为%d的信息\t",did);
    tranvest(head);
	save(head);
	catalog(head);
}
//更改信息
void change(struct person *head){
    int n=0,c=0,d=0,e=0;
	struct person *h;
	h=head;
    printf("1.姓名       ");
	printf("2.学号\n");
	printf("选择输入信息");
	while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
	if(n==1){
	char fname[10];
    printf("请输入学生姓名:");
	scanf("%s",fname);
	while(h!=NULL){
		if(strcmp(h->name,fname)==0){
		   printf("请选择你要修改的信息:\n");
		   printf("1.姓名\n2.学号\n3.语文成绩\n4.数学成绩\n5.英语成绩\n");
		   while(!scanf("%d",&c)){
	                   printf("输入格式有误，请重新输入");
	                    fflush(stdin);
				}
		   if(c==1){
			   printf("修改为:");
			   scanf("%s",h->name);}
		   if(c==2){
			   printf("修改为:");
			   	while(!scanf("%d",&h->id)){
	                   printf("输入格式有误，请重新输入");
	                    fflush(stdin);
				}
		   }
		   if(c==3){
			   printf("修改为:");
		       	while(!scanf("%d",&h->chinesegrade)){
	                  printf("输入格式有误，请重新输入");
	               fflush(stdin);
				}
		   }
		   if(c==4){
			   printf("修改为:");
			   	while(!scanf("%d",&h->mathgrade)){
	                    printf("输入格式有误，请重新输入");
	                    fflush(stdin);
				}


		   }
		   if(c==5){
			   printf("修改为:");
			   	while(!scanf("%d",&h->englishgrade)){
	                printf("输入格式有误，请重新输入");
	                fflush(stdin);
				}
		   }
		   printf("\t姓名\t学号\t语文成绩\t数学成绩\t英语成绩\t\n");
		   printf("------------------------------------------------------------\n");
		   printf("\t%s\t%d\t%d\t\t%d\t\t%d\n",h->name,h->id,h->chinesegrade,h->mathgrade,h->englishgrade);
		   save(head);
		   ++d;
		}
		h=h->next;
	}
	if(d==0){printf("查无此人");}
    printf("1.继续修改         2.返回主目录");
    while(!scanf("%d",&e)){
	                printf("输入格式有误，请重新输入");
	                fflush(stdin);
				}
	if(e==1){change(head);}
	if(e==2){catalog(head);}
	}
	if(n==2){
	    int fid;
		printf("请输入学生学号:");
		while(!scanf("%d",&fid)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
	while(h!=NULL){
		if(h->id==fid){
		   printf("请选择你要修改的信息:\n");
		   printf("1.姓名\n2.学号\n3.语文成绩\n4.数学成绩\n5.英语成绩\n");
		   while(!scanf("%d",&c)){
	                   printf("输入格式有误，请重新输入");
	                    fflush(stdin);
				}
		   if(c==1){
			   printf("修改为:");
			   scanf("%s",h->name);}
		   if(c==2){
			   printf("修改为:");
			   	while(!scanf("%d",&h->id)){
	                   printf("输入格式有误，请重新输入");
	                    fflush(stdin);
				}
		   }
		   if(c==3){
			   printf("修改为:");
		       	while(!scanf("%d",&h->chinesegrade)){
	                  printf("输入格式有误，请重新输入");
	               fflush(stdin);
				}
		   }
		   if(c==4){
			   printf("修改为:");
			   	while(!scanf("%d",&h->mathgrade)){
	                    printf("输入格式有误，请重新输入");
	                    fflush(stdin);
				}


		   }
		   if(c==5){
			   printf("修改为:");
			   	while(!scanf("%d",&h->englishgrade)){
	                printf("输入格式有误，请重新输入");
	                fflush(stdin);
				}
		   }
		   printf("\t姓名\t学号\t语文成绩\t数学成绩\t英语成绩\t\n");
		   printf("------------------------------------------------------------\n");
		   printf("\t%s\t%d\t%d\t\t%d\t\t%d\n",h->name,h->id,h->chinesegrade,h->mathgrade,h->englishgrade);
		   save(head);
		}
		h=h->next;
	}
	printf("1.继续修改         2.返回主目录");
    while(!scanf("%d",&e)){
	                printf("输入格式有误，请重新输入");
	                fflush(stdin);
				}
	if(e==1){change(head);}
	if(e==2){catalog(head);}
	}
	else{
	   printf("选择错误，请重新选择\n");
	   change(head);
    }
}
//按名字查找
void namefind(struct person *head){
	char fname[10];
	int n=0;
    struct person *h;
	h=head;
    printf("请输入学生姓名:");
	scanf("%s",fname);
	while(h!=NULL){
		if(strcmp(h->name,fname)==0){
		   printf("\t姓名\t学号\t语文成绩\t数学成绩\t英语成绩\t\n");
		   printf("------------------------------------------------------------\n");
		   printf("\t%s\t%d\t%d\t\t%d\t\t%d\n",h->name,h->id,h->chinesegrade,h->mathgrade,h->englishgrade);
		   ++n;
		}
		h=h->next;
	}
	if(n==0){
	    printf("查无此人");
	}
	catalog(head);
}
//按学号查找
void idfind(struct person *head){
	int fid=0;
    struct person *h;
	h=head;
    printf("请输入学生学号:");
	while(!scanf("%d",&fid)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
	while(h!=NULL&&h->id!=fid){
		h=h->next;
	}
	if(h==NULL){
	   printf("该学号学生不存在,请重新输入\n");
	   idfind(head);
	}
	else{
		   printf("\t姓名\t学号\t语文成绩\t数学成绩\t英语成绩\t\n");
		   printf("------------------------------------------------------------\n");
		   printf("\t%s\t%d\t%d\t\t%d\t\t%d\n",h->name,h->id,h->chinesegrade,h->mathgrade,h->englishgrade);
	}
	catalog(head);
}
//科目分段
void yuwenfenduan(struct person *head){
    int grade,a=0,b=0,c=0,d=0,e=0;
	struct person *h;
	h=head;
	while(h!=NULL){
         grade=h->chinesegrade;
		 if(grade<=100&&grade>90){++a;}
		 if(grade<=90&&grade>80){++b;}
         if(grade<=80&&grade>70){++c;}
		 if(grade<=70&&grade>60){++d;}
		 if(grade<=60){++e;}
    h=h->next;
	}
    printf("语文成绩分段统计\n");
	printf("(90,100]:%d\n",a);
    printf("(80,90]:%d\n",b);
	printf("(70,80]:%d\n",c);
	printf("(60,70]:%d\n",d);
	printf("(0,60]:%d\n",e);
	catalog(head);
}
void shuxuefenduan(struct person *head){
    int grade,a=0,b=0,c=0,d=0,e=0;
	struct person *h;
	h=head;
	while(h!=NULL){
         grade=h->mathgrade;
		 if(grade<=100&&grade>90){++a;}
		 if(grade<=90&&grade>80){++b;}
         if(grade<=80&&grade>70){++c;}
		 if(grade<=70&&grade>60){++d;}
		 if(grade<=60){++e;}
    h=h->next;
	}
    printf("数学成绩分段统计\n");
	printf("(90,100]:%d\n",a);
    printf("(80,90]:%d\n",b);
	printf("(70,80]:%d\n",c);
	printf("(60,70]:%d\n",d);
	printf("(0,60]:%d\n",e);
    catalog(head);
}
void yingyufenduan(struct person *head){
    int grade,a=0,b=0,c=0,d=0,e=0;
	struct person *h;
	h=head;
	while(h!=NULL){
         grade=h->englishgrade;
		 if(grade<=100&&grade>90){++a;}
		 if(grade<=90&&grade>80){++b;}
         if(grade<=80&&grade>70){++c;}
		 if(grade<=70&&grade>60){++d;}
		 if(grade<=60){++e;}
    h=h->next;
	}
    printf("英语成绩分段统计\n");
	printf("(90,100]:%d\n",a);
    printf("(80,90]:%d\n",b);
	printf("(70,80]:%d\n",c);
	printf("(60,70]:%d\n",d);
	printf("(0,60]:%d\n",e);
    catalog(head);
}
//科目平均
void yuwenpingjun(struct person *head){
	int sum=0,n=0;
	while(head!=NULL){
	   sum+=head->chinesegrade;
	   head=head->next;
	   ++n;
	}
	printf("该科目平均成绩:%d",sum/n);
	catalog(head);
}
void shuxuepingjun(struct person *head){
	int sum=0,n=0;
	while(head!=NULL){
	   sum+=head->mathgrade;
	   head=head->next;
	   ++n;
	}
	printf("该科目平均成绩:%d",sum/n);
	catalog(head);
}
void yingyupingjun(struct person *head){
	int sum=0,n=0;
	while(head!=NULL){
	   sum+=head->mathgrade;
	   head=head->next;
	   ++n;
	}
	printf("该科目平均成绩:%d",sum/n);
	catalog(head);
}
//个人平均
int studentpignjun(struct person *head){
    int n,grade;
	int sid;
	char sname[10];
    printf("1.姓名\n");
	printf("2.学号\n");
	printf("请选择输入学生信息:");
	scanf("%d",&n);
	if(n==1){
	printf("请输入学生姓名:");
	scanf("%s",sname);
	while(head!=NULL){
		if(strcmp(head->name,sname)==0){
	        grade=(head->chinesegrade)+(head->mathgrade)+(head->mathgrade);
			printf("该学生的平均成绩为:%d",(grade)/3);
			catalog(head);
			return 0;
		}
		head=head->next;
	}
	}
	if(n==2){
	printf("请输入学生学号:");
	while(!scanf("%d",&sid)){
      printf("输入格式有误，请重新输入");
	  fflush(stdin);
	}
	while(head!=NULL){
		if(head->id==sid){
	        grade=(head->chinesegrade)+(head->mathgrade)+(head->mathgrade);
			printf("该学生的平均成绩为:%d",(grade)/3);
			catalog(head);
			return 0;
		}
		head=head->next;
	}
	}
	else{
		printf("指令错误,,重新选择\n");
        studentpignjun(head);
	}
    	catalog(head);
		return 0;
}
//成绩排序
void yuwenpaixu(struct person *head){
     int i,j,len=0;
     struct person *p,*q,*tmp,*h;
     struct person *subhead;
	 struct person *pre,*nhead;
	 pre=(struct person*)malloc(sizeof(struct person));
	 pre->chinesegrade=NULL;
	 pre->mathgrade=NULL;
	 pre->englishgrade=NULL;
	 pre->next=head;
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
	    	if(p->chinesegrade>q->chinesegrade){
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
	   nhead=pre->next;
      tranvest(nhead);
	  free(pre);
	catalog(head);
}
void shuxuepaixu(struct person *head){
     int i,j,len=0;
     struct person *p,*q,*tmp,*h;
     struct person *subhead;
	 struct person *pre,*nhead;
	 pre=(struct person*)malloc(sizeof(struct person));
	 pre->chinesegrade=NULL;
	 pre->mathgrade=NULL;
	 pre->englishgrade=NULL;
	 pre->next=head;
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
	    	if(p->mathgrade>q->mathgrade){
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
	  nhead=pre->next;
      tranvest(nhead);
	  free(pre);
	  catalog(head);
}
void yingyupaixu(struct person *head){
          int i,j,len=0;
     struct person *p,*q,*tmp,*h;
     struct person *subhead;
	 struct person *pre,*nhead;
	 pre=(struct person*)malloc(sizeof(struct person));
	 pre->chinesegrade=NULL;
	 pre->mathgrade=NULL;
	 pre->englishgrade=NULL;
	 pre->next=head;
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
	    	if(p->englishgrade>q->englishgrade){
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
	   nhead=pre->next;
      tranvest(nhead);
	  free(pre);
       catalog(head);
}
//分段查询目录
void subject1(struct person *head){
	int n;
	printf("1.语文\n");
	printf("2.数学\n");
	printf("3.英语\n");
	printf("请输入选择的学科:");
		while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
	switch(n){
	case 1:yuwenfenduan(head);break;
	case 2:shuxuefenduan(head);break;
	case 3:yingyufenduan(head);break;
	default:printf("输入错误,重新选择\n");subject1(head);
	}
}
//平均成绩目录
void subject2(struct person *head){
	int n=0;
	printf("1.语文\n");
	printf("2.数学\n");
	printf("3.英语\n");
	printf("请输入选择的学科:");
    while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
	switch(n){
	case 1:yuwenpingjun(head);break;
	case 2:shuxuepingjun(head);break;
	case 3:yingyupingjun(head);break;
	default:printf("输入错误,重新选择\n");subject2(head);
	}
}
//信息维护目录
void catalog1(struct person *head){
	int n=0;
	printf("1.增加学生信息\n");
	printf("2.删除学生信息\n");
	printf("3.修改学生信息\n");
    printf("4.返回目录\n");
	  printf("请输入你要进行的操作:");
    while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	};
    switch(n){
	    case 1:add(head);break;
	    case 2:deletion(head);break;
		case 3:change(head);break;
		case 4:catalog(head);break;
		default:printf("输入错误,重新选择\n");catalog1(head);
		}
}
//信息查找目录
void catalog2(struct person *head){
	int n=0;
    printf("1.按姓名查询\n");
	printf("2.按学号查询\n");
	printf("3.返回目录\n");
	printf("请输入你要进行的操作:");
    while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
    switch(n){
	    case 1:namefind(head);break;
	    case 2:idfind(head);break;
		case 3:catalog(head);break;
		default:printf("输入错误,重新选择\n");catalog2(head);
		}
}
//成绩统计目录
void catalog3(struct person *head){
     int n=0;
	 printf("1.分段查询\n");
	 printf("2.学科平均成绩\n");
	 printf("3.个人平均成绩\n");
	 printf("4.返回目录\n");
	 printf("请输入你要进行的操作:");
     while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
     switch(n){
	    case 1:subject1(head);break;
	    case 2:subject2(head);break;
		case 3:studentpignjun(head);break;
		case 4:catalog(head);break;
		default:printf("输入错误,重新选择\n");catalog3(head);
		}
}
//成绩排序目录
void catalog4(struct person *head){
      int n;
	  printf("1.按语文成绩排序\n");
      printf("2.按数学成绩排序\n");
	  printf("3.按英语成绩排序\n");
	  printf("4.返回目录\n");
	  printf("请输入你要进行的操作:");
      while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
      switch(n){
	    case 1:yuwenpaixu(head);break;
	    case 2:shuxuepaixu(head);break;
		case 3:yingyupaixu(head);break;
		case 4:catalog(head);break;
		default:printf("输入错误,重新选择\n");catalog4(head);
		}
}
void stop(int n){
	printf("按任意键退出");
   exit(-1);
}
//主目录
void catalog(struct person *head){
   int n;
   printf("\n");
   printf("\n");
   printf("----------------------学生成绩管理系统--------------------------\n");
   printf("                       1.信息维护\n");
   printf("                       2.信息查询\n");
   printf("                       3.成绩统计\n");
   printf("                       4.成绩排序\n");
   printf("                       5.成绩目录\n");
   printf("                       6.退出系统\n");
   printf("----------------------------------------------------------------\n");
   printf("\n");
   printf("\n");
   printf("请输入你要进行的操作:");
   while(!scanf("%d",&n)){
	   printf("输入格式有误，请重新输入");
	   fflush(stdin);
	}
   switch(n){
	    case 1:catalog1(head);break;
	    case 2:catalog2(head);break;
		case 3:catalog3(head);break;
		case 4:catalog4(head);break;
		case 5:tranvest(head);catalog(head);break;
		case 6:stop(n);break;
		default:printf("输入错误,重新选择\n");catalog(head);
		}
}
//读取文件
struct person*  read(){
	 FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	struct person *pre,*q,*head;
	int n=1;

	pre=q=head;
	fp1=fopen("名字.txt","r");
    fp2=fopen("学号.txt","r");
	fp3=fopen("语文成绩.txt","r");
	fp4=fopen("数学成绩.txt","r");
	fp5=fopen("英语成绩.txt","r");
    if(fp1==NULL||fp2==NULL||fp3==NULL||fp4==NULL||fp5==NULL){
            printf("此文件打不开");
            return NULL;
	}
	while(!feof(fp1)){
		 q=(struct person*)malloc(sizeof(struct person));
		 fscanf(fp1,"%s",q->name);
		 fscanf(fp2,"%d",&q->id);
		 fscanf(fp3,"%d",&q->chinesegrade);
		 fscanf(fp4,"%d",&q->mathgrade);
		 fscanf(fp5,"%d",&q->englishgrade);
		 if(n==1){
		   pre=q;
		   head=q;
		   ++n;
		 }
		 else{
		 pre->next=q;
			pre=q;
		}
		 q->next= NULL;

	   }
	   fclose(fp1);
	    return head;
}
//储存到文件
int save(struct person *head)
{
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	struct person *p;
	p=head;
	fp1=fopen("名字.txt","w");
    fp2=fopen("学号.txt","w");
	fp3=fopen("语文成绩.txt","w");
	fp4=fopen("数学成绩.txt","w");
	fp5=fopen("英语成绩.txt","w");
    if(fp1==NULL||fp2==NULL||fp3==NULL||fp4==NULL||fp5==NULL){
            printf("此文件打不开");
            return -1;
	}
    while(head->next!=NULL){
		fprintf(fp1,"%s\n",head->name);
		fprintf(fp2,"%d\n",head->id);
		fprintf(fp3,"%d\n",head->chinesegrade);
		fprintf(fp4,"%d\n",head->mathgrade);
		fprintf(fp5,"%d\n",head->englishgrade);
		head=head->next;
   }
        fprintf(fp1,"%s",head->name);
		fprintf(fp2,"%d",head->id);
		fprintf(fp3,"%d",head->chinesegrade);
		fprintf(fp4,"%d",head->mathgrade);
		fprintf(fp5,"%d",head->englishgrade);
    fclose (fp1);
	fclose (fp2);
	fclose (fp3);
	fclose (fp4);
	fclose (fp5);
	return 1;
}

int main(int argc, char* argv[])
{

	struct person* head;
	head=read();
	catalog(head);
    releas(head);
	return 0;
}
*/
