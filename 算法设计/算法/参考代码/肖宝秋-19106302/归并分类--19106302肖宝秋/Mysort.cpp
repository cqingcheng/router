#include<iostream.h>
#include<fstream.h>
#include<time.h>
#include<stdlib.h>
#define NUM 500
char filename[]="data500.txt"; 
int data[NUM+1];
int LINK[NUM+1]={0};
#define INFINITE 10000  
void Readdata()   //�ļ���������
{
	ifstream fin;
	fin.open(filename);
	for(int i=1;i<NUM+1;i++)
		fin>>data[i];
	cout<<"��ʼ����:\n";
	for(i=1;i<NUM+1;i++)
	{
		cout.width(4);
		cout<<data[i]<<" ";
	}
	cout<<endl;
}
//��low--high��Ԫ�ذ��ǽ�������
void INSERTSORT(int low,int high,int &p)   //ֱ�Ӳ�������
{
	int MIN=data[low],item=INFINITE;
	p=low;                                 //��ʼ�������
	for(int i=low;i<high;i++)
	{
        item=INFINITE;LINK[i]=0;
		if(data[i]<MIN) {p=i;MIN=data[i];}
		for(int j=low;j<high;j++)
		{
			if(data[i]<data[j] && data[j]<item)
			{
				 LINK[i]=j;
				 item=data[j];
			}
		}
	}
}
void MERGE1(int q,int r,int &p)
{
	int i=q,j=r,k=0;
	while(i!=0&&j!=0)            //��0��ʾ����
	{ 
		if(data[i] <= data[j]) 	 //�ҽ�С�ؼ���
		{
			LINK[k]=i;
			k=i;
			i=LINK[i];
		}                       //��һ���µĹؼ��ֵ��˱�
		else  
		{
			LINK[k]=j;
			k=j;
			j=LINK[j];
		}
	}
	if(i==0) LINK[k]=j;
	else LINK[k]=i;
	p=LINK[0];
}
void MERGESORT1(int low,int high,int &p)
{
	int mid,q,r;
	if(high-low<=10)
		INSERTSORT(low,high,p);
	else 
	{
		mid=(low+high)/2;
		MERGESORT1(low,mid,q);
		MERGESORT1(mid,high,r);
		MERGE1(q,r,p);
	}
}
void main()
{	
	ofstream fout;
	fout.open("result.txt");   //����ļ�
	int p;
	Readdata();
	MERGESORT1(1,NUM+1,p);
	//cout<<"pֵ:"<<p<<endl;
	//cout<<"LINK����ֵ:"<<endl;
	//for(int i=1;i<NUM+1;i++)
	//	cout<<LINK[i]<<"\t";
	//cout<<endl;
	cout<<"�����ֵ:"<<endl;
	for(int i=1;i<NUM+1;i++)
	{
        cout<<data[p]<<"\t";
		p=LINK[p];
        fout<<data[p]<<"\t";
	}
}