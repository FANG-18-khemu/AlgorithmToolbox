#include<iostream>
using namespace std;

long long fibo(long long n)
{
	long long prev= 0;
	long long cur =1;
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	
	for(int i=0;i<n-1;i++)
	{
		long long temp=cur;
		cur= (prev + cur);
		prev = temp;
	}
	return cur%10;
}
int main()
{
	long long n;
	cin>>n;

	cout<<fibo(n);
	return 0;
}
