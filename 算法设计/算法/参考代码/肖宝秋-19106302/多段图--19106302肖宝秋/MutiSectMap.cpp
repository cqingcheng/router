#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
int n,k,*P,*D,*COST,**E;  //p����С�ɱ�·����d�Ǿ���,E��ͼ�ľ���n�ǽڵ������k�Ƕε���
int Mymalloc()
{
	int returnvalue=1;
	if((E=(int **)malloc((n+1)*sizeof(int *)))==NULL)
	{
		cout<<"�ռ�����ʧ��!";
		returnvalue=0;
	}
    for(int i=1;i<n+1;i++)
	{
		if((E[i]=(int *)malloc((n+1)*sizeof(int)))==NULL)
		{
			cout<<"�ռ�����ʧ��!";
			returnvalue=0;
		}	
	}
	if((P=(int*)malloc((k+1)*sizeof(int)))==NULL||(D=(int*)malloc(n*sizeof(int)))==NULL||(COST=(int*)malloc((n+1)*sizeof(int)))==NULL)   
	{
		cout<<"�ռ�����ʧ��!";
		returnvalue=0;
	}
	return returnvalue;
}
void FGRAPH()
{
	COST[n]=0;     //���һ���ڵ�
	cout<<"COST["<<n<<"]="<<COST[n]<<"\n";
    for(int j=n-1;j>0;j--)   //j֮ǰ��costֵһ���Ѿ�������
	{
        int r,min=100;
		for(int i=j+1;i<n+1;i++)    //�ҵ�r
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
	cout<<"���·��:";
	for(j=1;j<=k;j++)
		cout<<P[j]<<"\t";
	cout<<"\n���·������:"<<COST[1]<<endl;
}
void BGRAPH()
{
	COST[1]=0;     //���һ���ڵ�
	cout<<"COST["<<n<<"]="<<COST[1]<<"\n";
    for(int j=2;j<=n;j++)   //j֮ǰ��costֵһ���Ѿ�������
	{
        int r,min=1000;
		for(int i=1;i<j;i++)    //�ҵ�r
			if(E[i][j]+COST[i]<min) {min=E[i][j]+COST[i];r=i;}
        COST[j]=E[r][j]+COST[r];
		cout<<"COST["<<j<<"]="<<COST[j]<<"\t";
		D[j]=r;
		cout<<"D["<<j<<"]="<<D[j]<<"\n";
	}
	P[1]=1;P[k]=n;
	for(j=k-1;j>=2;j--)
	{
		P[j]=D[P[j+1]];
	}
	cout<<"���·��:";
	for(j=1;j<=k;j++)
		cout<<P[j]<<"\t";
	cout<<"\n���·������:"<<COST[12]<<endl;
}
void InputData()
{
	ifstream fin;
	fin.open("data.txt");
	cout<<"�ε���Ŀ:";
	cin>>k;
	cout<<"�ڵ���Ŀ:";
	cin>>n;
	if(Mymalloc()==0)  //�ռ�����
		return;
	for(int i=1;i<=n;i++)    //ͼ�ľ���
		for(int j=1;j<=n;j++)
			fin>>E[i][j];
}
void Select_Fun()
{
	char select;
	while(1)
	{
		cout<<"��ѡ�񷽷�(f:��ǰ----b:���---q:�˳�):";
		cin>>select;
		if(select=='f'||select=='F') FGRAPH();
		else if(select=='b'||select=='B') BGRAPH();
		else if(select=='q'||select=='Q') break;
		cout<<endl;
	}
}
void main()
{
	InputData();
	Select_Fun();
}