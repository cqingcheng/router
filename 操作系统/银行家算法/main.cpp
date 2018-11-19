#include<iostream>
using namespace std;


int Max(int *A,int n)
{
    int k;
    if(n==1)
    {
        int max=A[0];
        return max;
    }
    else
    {
        k=Max(A,n-1);
    }
    int max=(A[n-1]>k)?A[n-1]:k;
    return max;
}


int Sum(int *A,int n)
{
    if(n==1)
    {
        int sum=A[0];
        return sum;
    }
    else
    {
        int sum=A[n-1]+Sum(A,n-1);
        return sum;
    }
}


float Avr(int *A,int n)
{
    if(n==1)
    {
        float avr=A[0];
        return avr;
    }
    else
    {
        float avr=(A[n-1]+(n-1)*Avr(A,n-1))/n;
        return avr;
    }
}


int main()
{
    int a[5]={3,1,2,5,4};
    int n=5;
    int max=Max(a,5);
    cout<<"max："<<max<<endl;
    int sum=Sum(a,5);
    cout<<"sum："<<sum<<endl;
    float avr=Avr(a,5);
    cout<<"average："<<avr<<endl;
    return 0;

}





