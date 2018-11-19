#include <iostream>
#include <fstream>
#define n 3
using namespace std;
int cost[n+1][n+1];
int main()
{
    ifstream ifile;
	ifile.open("duoduan.txt");
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
			ifile>>cost[i][j];
	}
	ifile.close();
	int i,j,k,min;
	int a[n+1][n+1];
	for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            a[i][j]=cost[i][j];
        }
	}
	for(k=1;k<=n;++k){
            for(i=1;i<=n;++i){
                for(j=1;j<=n;++j){
                min=(a[i][j]<(a[i][k]+a[k][j]))?a[i][j]:(a[i][k]+a[k][j]);
                a[i][j]=min;
                cout<<a[i][j]<<"  ";
                }
                cout<<endl;
                }
                cout<<endl;
    }

}
