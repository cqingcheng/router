#include <iostream>
#include<fstream>
#define n 6
using namespace std;

int main()
{
    int a[n+1][n+1];
    ifstream ifile;
	ifile.open("tu.txt");
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
			ifile>>a[i][j];
	}
	ifile.close();
    int near[n+1];
    int i,j,k,l,mina,m=100,f;
    int t[n][3];
    //Ѱ����С
    k=1,l=2;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)
        {
            if(i==j){}
            else{
               if(a[i][j]<a[k][l]){k=i;l=j;}}
        }
        }
        t[1][1]=k;
        t[1][2]=l;
        mina=a[k][l];
        //Ѱ������̱߶˵������ĵ�
      for(i=1;i<=n;++i){
        if(a[i][l]<a[i][k]){
            near[i]=l;
        }
        else{near[i]=k;}
      }
      //Ѱ�������ĵ���Ȩ����С
      near[k]=0;
      near[l]=0;
      for(i=2;i<n;++i){
            m=100;
		for(j=1;j<=n;j++)  //����С��jֵ
		{
			if(near[j]!=0)
			{
				if(a[j][near[j]]<m&&a[j][near[j]]>0)
				{m=a[j][near[j]];f=j;}
			}
		}
		j=f;
		t[i][1]=j;
		t[i][2]=near[j];
		mina=mina+a[j][near[j]];
		near[j]=0;
		for(k=1;k<=n;++k)   //�޸�nearֵ
		{
			if(near[k]!=0&&a[k][near[k]]>a[k][j]&&a[k][near[k]]>0)
				near[k]=j;
		}
	}
         cout<<endl;
	  for(int p=1;p<n;p++)
	    {
		cout<<t[p][1]<<" "<<t[p][2]<<" "<<a[t[p][1]][t[p][2]]<<endl;
	   }

	  if(mina>1000) cout<<"no spanning tree!";
	  else cout<<"��С��������·������:"<<mina<<endl;
}
