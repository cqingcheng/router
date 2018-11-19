#include<iostream>
#include<fstream>
#include <windows.h>
#define n 6
using namespace std;
int cost[n+1][n+1];

int main(){
   ifstream ifile;
   int i,j;
	ifile.open("tu.txt");
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
			ifile>>cost[i][j];
	}
	ifile.close();
    int s[n+1],dist[n+1];
    int u,v=1,num,w,k,min;
    cin>>v;
    for(i=1;i<=n;++i){
        s[i]=0;
        dist[i]=cost[v][i];
    }
     s[v]=1;
     dist[v]=0;
     for(num=2;num<n;++num){
            k=100;
        for(w=1;w<n;++w){
            if(dist[w]<k&&s[w]==0){
                k=dist[w];
                u=w;
            }
        }
        s[u]=1;
        for(w=1;w<=n;++w){
            if(s[w]==0){
                min=(dist[w]<(dist[u]+cost[u][w]))?dist[w]:(dist[u]+cost[u][w]);
                dist[w]=min;
            }
        }
     }

     for(i=1;i<=n;++i){
            if(dist[i]!=100)
        cout<<"节点"<<v<<"到"<<i<<"  "<<dist[i]<<endl;
     else{
        cout<<"节点"<<v<<"无法到达"<<i<<endl;
     }
     }




}
