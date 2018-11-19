#include <iostream>
int a[10]={13,27,19,2,8,12,2,8,30,86};
int b[10];
using namespace std;

void guibing(int a[],int s,int m,int e,int tmp[]){
   int p=s,q=m+1;
   int d=0;
   while(p<=m&&q<=e){
    if(a[p]<a[q]){
        tmp[d++]=a[p++];
    }
    else{
      tmp[d++]=a[q++];
    }
   }
   while(p<=m) tmp[d++]=a[p++];
   while(q<=e) tmp[d++]=a[q++];
   for(int i=0;i<e-s+1;++i){a[s+i]=tmp[i];}
}

void paixu(int a[],int s,int e,int tmp[]){
   if(s<e){
    int m=s+(e-s)/2;
    paixu(a,s,m,tmp);
    paixu(a,m+1,e,tmp);
    guibing(a,s,m,e,tmp);
   }
}

int main()
{


    int sized=sizeof(a)/sizeof(int);
    paixu(a,0,sized-1,b);
    for(int i=0;i<sized;++i){
        cout<<a[i]<<","<<endl;
    }


}
