#include<stdio.h>
#define max 100

int n,k,num[max],start[max],path[max],d[max],w[max][max],cost[max],i,j,ll;

//cost[k]  �����k�ڵ㵽Դ��s����С�ɱ� 


void bgraph()
{
	int i,j,p,min;
	for(i=start[2];i<start[3];i++)
	{
		d[i]=1;
		cost[i]=w[i][1];
	}

	for(i=2;i<=k-1;i++)
	{
		int pos;
		for(p=start[i+1];p<start[i+2];p++)
		{
			min=0x7fffffff;
			for(j=start[i];j<start[i+1];j++)
			{
				if(w[p][j]>0&&cost[j]+w[p][j]<min)
				{
					pos=j;
					min=cost[j]+w[p][j];
				}

			}
			cost[p]=min;
			d[p]=pos;
		}
	}
	path[1]=1;
	path[k]=n;
	for(i=k-1;i>=2;i--)path[i]=d[path[i+1]];
	printf("��С���ѣ�%d\n",cost[n]);
	printf("·����");
	for(i=k;i>=1;i--)printf("%d ",path[i]);
	printf("\n");
}

int main()
{
	printf("������ڵ���ܸ������ܶ�����\n");
	scanf("%d%d",&n,&k);
	printf("������ÿ�εĽڵ�����\n");
    for(i=1;i<=k;i++)scanf("%d",&num[i]);
	num[1]=1;
	num[k]=1;
	start[1]=1;
	for(i=2;i<=k;i++)start[i]=start[i-1]+num[i-1];
	start[k+1]=start[k]+1;
	printf("·��������\n");
	scanf("%d",&ll);
	for(i=1;i<=ll;i++)
	{
		int vv,uu,len;
		scanf("%d%d%d",&vv,&uu,&len);
		w[vv][uu]=len;
		w[uu][vv]=len;
	}
	bgraph();
	return 0;
}