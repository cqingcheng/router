#include<iostream>
#include<fstream>
#include<stdlib.h>
#define NUM 7
using namespace std;
//filename�ļ�����n�Ǿ����С��data��ž�������
void ReadData(char* filename,int n,int data[NUM][NUM])
{
	ifstream fin;
	fin.open(filename);
	for(int i=0;i<n;i++)     //������Ϣ
	{
		for(int j=0;j<n;j++)
			fin>>data[i][j];
	}
}
//v��ʾ��ʼ�ӵ㣬n��ʾ�����С��COST��ʾ�ɱ�����DIST��ʾv�������ӵ�ľ���
void SHORTEST_PATHS(int v,int n,int COST[NUM][NUM],int DIST[NUM],bool S[NUM])
{
	int index=0;
	int i,num;
	for( i=0;i<n;i++)
	{
		S[i]=0;
        DIST[i]=COST[v][i];
	}
	S[v]=1;
    DIST[v]=0;
	for(num=1;num<n;num++)     //��v������ӵ�ľ���
	{
		int min=10001,k=0;
		for(int i=0;i<n;i++)       //����̵�DIST[v]
			if(S[i]!=1&&DIST[v]<min)
			{min=DIST[v];k=i;}


        S[k]=1;
        for(i=0;i<n;i++)          //���¾���
		{
            if(S[i]!=1&&DIST[k]+COST[k][i]<DIST[i])
				DIST[i]=DIST[k]+COST[k][i];
		}
	}
}
int main()
{
	int start;
	int DIST[NUM];
	bool S[NUM];
	int COST[NUM][NUM];
	char filename[]="data.txt";
	cout<<"��ʼ�ڵ�(0--"<<NUM<<"):";
	cin>>start;
	ReadData(filename,NUM,COST);               //���ݶ��뵽����
	SHORTEST_PATHS(start,NUM,COST,DIST,S);
	for(int i=0;i<NUM;i++)
		cout<<DIST[i]<<"\t";
	cout<<"\n";
}
