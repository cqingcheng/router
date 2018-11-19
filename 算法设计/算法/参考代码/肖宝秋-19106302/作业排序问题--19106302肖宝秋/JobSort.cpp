#include<iostream.h>
#define MIN(x,y) x>y?y:x
int V[8]={0,35,30,25,20,15,10,5};  //��ֵ
int D[8]={0,4,2,4,3,4,8,3};        //����
int J[8]={0,0,0,0,0,0,0,0};        //���Ž�
int P[8];    //���ڵ�
int F[8];    //��ӽ�i�Ŀ���λ��
int k=0;
int n=8;     //��ҵ��+1
//////////////////////////////////
int FIND(int i)
{
	int j,k,t;
	j=i;
	while(P[j]>0)
		j=P[j];
	k=i;
	while(k!=j)
	{
		t=P[k];
		P[k]=j;
		k=t;
	}
	return j;   
}
////////////////////////////////////
int UNION(int i,int j)
{
	int x;
	x=P[i]+P[j];
	if(P[i]>P[j])     
	{
		P[i]=j;    //i�Ľڵ���
		P[j]=x;
	}
	else
	{
		P[j]=i;     //j�Ľڵ���
		P[i]=x;
	}
	return 1;
}
//////////////////////////////////
void FJS()
{
	int j,l;
	for(int i=0;i<n;i++)   //��ʼ��		F[i];P[i]
	{	
		F[i]=i;
		P[i]=-1;
	}
	k=0;
	for(i=1;i<n;i++)                  //̰�Ĺ���
	{
		j=FIND(MIN(n,D[i]));
		if(F[j]!=0)                  //ѡ����ҵi
		{
			k=k+1;
			J[k]=i;   
			l=FIND(F[j]-1);
			UNION(l,j);
			F[j]=F[l];
		}
	}   
}
////////////////////////////////
void main()
{
	FJS();
	cout<<"ѡ�����ҵ��:  "<<k<<endl;
	cout<<"ѡ����ҵ���:  ";
	for(int i=1;i<n;i++)
		cout<<J[i]<<"\t";
	cout<<endl;
}