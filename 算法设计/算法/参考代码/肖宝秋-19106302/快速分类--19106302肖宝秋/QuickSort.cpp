//һ��Ŀ�������ѡȡ��һ��Ԫ�ز���
#include<iostream.h>
#include<fstream.h>
#define NUM 11
int A[NUM+1+1]={0,125,10,65,70,75,80,85,60,55,50,45,1000};
void PARTITION(int m,int &p)
{
	int v=A[m];   //�ο�Ԫ��
	int i=m,flag=1;
	while(1)
	{
		do{i=i+1;}while(A[i]<=v && i<p);   //��֤��ԵҲ��ȷ
		do{p=p-1;}while(A[p]>=v && p>m);
		if(i<p)
		{
			int temp=A[i];
			A[i]=A[p];
			A[p]=temp;
		}
		else break;    //ѭ����������i<pʱ���ֹ
	}
	A[m]=A[p];A[p]=v;
}
void QUICKSORT(int p,int q)
{
	int j;
	if(p<q)
	{
		j=q+1;
		PARTITION(p,j);
		QUICKSORT(p,j-1);
		QUICKSORT(j+1,q);
	}
}
void main()
{
	cout<<"ԭʼ����:";
	for(int i=1;i<=NUM;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	QUICKSORT(1,NUM);
	cout<<"�������:";
	for(i=1;i<=NUM;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}