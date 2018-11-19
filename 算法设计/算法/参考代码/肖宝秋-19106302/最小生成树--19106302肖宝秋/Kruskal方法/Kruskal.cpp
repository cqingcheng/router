#include "iostream"
#include "fstream"
#define N 6
int mincost=0,COST[N+1][N+1];
int P[N+1]={-1},T[N][3];
struct EDGE        //�߼�
{
	int sour;      //���
	int dest;      //�յ�
	int weight;    //Ȩֵ
};
EDGE E[(N*N-N)/2+1];
int edgenum=0;   //����
void InputData()   //��������Ϣ,�������߼�
{
	ifstream fn;
	fn.open("data1.txt");
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			fn>>COST[i][j];
	for(i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(COST[i][j]>0 && COST[i][j]<100){E[edgenum].sour=i;E[edgenum].dest=j;E[edgenum].weight=COST[i][j];edgenum++;}
}
//headΪҪҪ�����ĸ��ڵ��±꣬nΪ�ܽڵ�����a[]����Ϊ����
void CreatHeap(EDGE a[],int n,int head)
{
	int i=head,j=2*i+1,flag=0;EDGE temp=a[i];
	while(j<n && flag!=1)
	{
		if(j<n-1 && a[j].weight>a[j+1].weight) j++;  //Ѱ�����Һ����н�С�Ľڵ�Ԫ��
		if(temp.weight < a[j].weight) flag=1;   //���õ���
		else{a[i]=a[j];i=j;j=2*i+1;}   //����
	}
	a[i]=temp;   //�����a[i]��ֵ������a[j]
}
int FIND(int i)
{
	int j=i,k,t;
	while(P[j]>0)j=P[j];
	k=i;
	while(k!=j){t=P[k];	P[k]=j;	k=t;}
	return j;
}
////////////////////////////////////
int UNION(int i,int j)
{
	int x=P[i]+P[j];
	if(P[i]>P[j]){P[i]=j; P[j]=x;}
	else{P[j]=i;P[i]=x;}
	return 1;
}
void main()
{
	int u,v,m,n;
    InputData();
	/*cout<<"���бߵ���Ϣ:\n";
	for(int i=0;i<edgenum;i++)
       cout<<E[i].sour<<"\t"<<E[i].dest<<"\t"<<E[i].weight<<endl;*/
	for(int i=(edgenum-1)/2;i>=0;i--)   //����С��
		CreatHeap(E,edgenum,i);
	int j=0;
	cout<<"ѡ��ı���Ϣ(���-�յ�-Ȩ��):"<<endl;
    for(i=edgenum-1;i>=0;i--)  //������С�ѽ�����С������
	{
		EDGE temp=E[0];
		E[0]=E[i];
        E[i]=temp;
        CreatHeap(E,i,0);

		m=temp.sour;n=temp.dest;
		u=FIND(m);
		v=FIND(n);
		if(u!=v)   //���ڵ㲻ͬ
		{
			T[j][1]=u;T[j][2]=v;
			j++;
           	cout<<m<<"\t"<<n<<"\t"<<temp.weight<<endl;   //��ѡ��ı�Ȩֵ
			mincost=mincost+temp.weight;
            UNION(u,v);
		}
	}
	cout<<"��С������·������:"<<mincost<<endl;
}
