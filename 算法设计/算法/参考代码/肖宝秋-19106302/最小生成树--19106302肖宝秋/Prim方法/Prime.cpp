#include<iostream>
#include<fstream>
#define N 6
int COST[N+1][N+1],mincost=1000;
int T[N][3],NEAR[N+1];
void InputData()   //��������Ϣ
{
	ifstream fin1;
	fin1.open("data1.txt");
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			fin1>>COST[i][j];
}
void main()
{
	InputData();
	int k,l;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(COST[i][j]<mincost&&COST[i][j]>0){mincost=COST[i][j];k=i;l=j;}
			 cout<<k<<endl<<l<<endl;
	T[1][1]=k;T[1][2]=l;
	for(i=1;i<=N;i++)    //��NEAR�ó�ֵ
		if(COST[i][l]>0&&COST[i][k]>0)
		{
			if(COST[i][l]<COST[i][k]) NEAR[i]=l;
			else NEAR[i]=k;
		}
	NEAR[k]=0;NEAR[l]=0;
	for(i=2;i<N;i++) //��T�������n-2����
	{
		int min=1000,flag;
		for(int j=1;j<=N;j++)  //����С��jֵ
		{
			if(NEAR[j]!=0)
			{
				if(COST[j][NEAR[j]]<min && COST[j][NEAR[j]]>0)
				{min=COST[j][NEAR[j]];flag=j;}
			}
		}
		//cout<<"i="<<i<<":flagֵ="<<flag<<endl;
		T[i][1]=flag;T[i][2]=NEAR[flag];
		mincost=mincost+COST[flag][NEAR[flag]];
		NEAR[flag]=0;
		for(int m=1;m<=N;m++)   //�޸�NEARֵ
		{
			if(NEAR[m]!=0 && COST[m][NEAR[m]]>COST[m][flag] && COST[m][NEAR[m]]>0)
				NEAR[m]=flag;
		}
	}
    /*cout<<"NEAR����:\n";
	for(int m=1;m<=N;m++)
		cout<<NEAR[m]<<" ";
	cout<<endl;*/

	cout<<"T����(��-��-Ȩֵ):\n";
	for(int m=1;m<N;m++)
	{
		cout<<T[m][1]<<" "<<T[m][2]<<" "<<COST[T[m][1]][T[m][2]]<<endl;
	}


	if(mincost>1000) cout<<"no spanning tree!";   //����ͨͼ
	else cout<<"��С��������·������:"<<mincost<<endl;
}
