#include<iostream>
#include<fstream>
#define N 6
using namespace std;
int mincost=0,COST[N+1][N+1];
int P[N+1]={-1},T[N][3];
struct EDGE
{
	int qd;
	int zd;
	int weight;
};
EDGE E[(N*N-N)/2+1];
int bianshu=0;
void InputData()
{
    int i=1;
	ifstream fin;
	fin.open("tu.txt");
	for(i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			fin>>COST[i][j];
	for(i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(COST[i][j]>0 && COST[i][j]<100){E[bianshu].qd=i;E[bianshu].zd=j;E[bianshu].weight=COST[i][j];bianshu++;}
}

void jianli(EDGE a[],int n,int head)
{
	int i=head,j=2*i+1,flag=0;EDGE temp=a[i];
	while(j<n && flag!=1)
	{
		if(j<n-1 && a[j].weight>a[j+1].weight) j++;
		if(temp.weight < a[j].weight) flag=1;
		else{a[i]=a[j];i=j;j=2*i+1;}
	}
	a[i]=temp;
}
int xunzhao(int i)
{
	int j=i,k,t;
	while(P[j]>0)j=P[j];
	k=i;
	while(k!=j){t=P[k];	P[k]=j;	k=t;}
	return j;
}

int UNION(int i,int j)
{
	int x=P[i]+P[j];
	if(P[i]>P[j]){P[i]=j; P[j]=x;}
	else{P[j]=i;P[i]=x;}
	return 1;
}
int  main()
{
	int u,v,m,n;
	int i;
    InputData();
	for(i=(bianshu-1)/2;i>=0;i--)
		jianli(E,bianshu,i);
	int j=0;
    for(i=bianshu-1;i>=0;i--)
	{
		EDGE temp=E[0];
		E[0]=E[i];
        E[i]=temp;
        jianli(E,i,0);
		m=temp.qd;n=temp.zd;
		u=xunzhao(m);
		v=xunzhao(n);
		if(u!=v)
		{
			T[j][1]=u;T[j][2]=v;
			j++;
           	cout<<m<<"\t"<<n<<"\t"<<temp.weight<<endl;
			mincost=mincost+temp.weight;
            UNION(u,v);
		}
	}
	cout<<"最小生成树路径长度:"<<mincost<<endl;
}
