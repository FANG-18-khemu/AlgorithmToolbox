#include<iostream>
using namespace std;

long long fibo(long n,long m)
{
    long long arr[n];
	
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<=n;i++)
	   arr[i]=(arr[i-1]+arr[i-2])%m;
	  
	return arr[n];   
}

int main()
{
	long long n;
	long long m;
	cin>>n>>m;
	cout<<fibo(n,m);
	return 0;
}
