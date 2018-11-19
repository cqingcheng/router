#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int n,k,*P,*D,*COST,**E;  //p是最小成本路径。d是决策,E是图的矩阵，n是节点个数，k是段的数
int Mymalloc()
{
	int returnvalue=1;
	if((E=(int **)malloc((n+1)*sizeof(int *)))==NULL)
	{
		cout<<"空间申请失败!";
		returnvalue=0;
	}
    for(int i=1;i<n+1;i++)
	{
		if((E[i]=(int *)malloc((n+1)*sizeof(int)))==NULL)
		{
			cout<<"空间申请失败!";
			returnvalue=0;
		}
	}
	if((P=(int*)malloc((k+1)*sizeof(int)))==NULL||(D=(int*)malloc(n*sizeof(int)))==NULL||(COST=(int*)malloc((n+1)*sizeof(int)))==NULL)
	{
		cout<<"空间申请失败!";
		returnvalue=0;
	}
	return returnvalue;
}
void FGRAPH()
{
    int j,i;
	COST[n]=0;     //最后一个节点
	cout<<"COST["<<n<<"]="<<COST[n]<<"\n";
    for(j=n-1;j>0;j--)   //计算cost
	{
        int r,min=100;
		for(i=j+1;i<n+1;i++)
			if(E[j][i]+COST[i]<min) {min=E[j][i]+COST[i];r=i;}
        COST[j]=E[j][r]+COST[r];
		cout<<"COST["<<j<<"]="<<COST[j]<<"\t";
		D[j]=r;
		cout<<"D["<<j<<"]="<<D[j]<<"\n";
	}
	P[1]=1;P[k]=n;
	for(j=2;j<k;j++)
	{
		P[j]=D[P[j-1]];
	}
	cout<<"最短路径:";
	for(j=1;j<=k;j++)
		cout<<P[j]<<"\t";
	cout<<"\n最短路径长度:"<<COST[1]<<endl;
}

void InputData()
{
	ifstream fin;
	fin.open("data.txt");
	cout<<"段的数目:";
	cin>>k;
	cout<<"节点数目:";
	cin>>n;
	if(Mymalloc()==0)  //空间申请
		return;
	for(int i=1;i<=n;i++)    //图的矩阵
		for(int j=1;j<=n;j++)
			fin>>E[i][j];
}

int main()
{
	InputData();
	FGRAPH();
}
