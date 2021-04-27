#include <iostream>
using namespace std;

long findthelenth(long long n)
{
	long pre=0;
	long cur=1;
	long res=0;
	
	for(int i =0;i<n*n;i++)
	{
		long temp=0;
		temp=cur;
		cur= (pre+cur)%n;
		pre= temp;
		
		if(pre ==0 && cur==1)
		{
			res= i+1;
		}
	}
	return res;
}
long long fibonaci(long long n,long long m)
{
	long num= findthelenth(m);
	n= n%num;
	 
	long long  pre=0;
	long long curr= 1;
	if(n==0)
	return 0;
	else if( n==1)
	return 1;
	
	for(int i =0;i<n-1;i++)
	{
		long long temp=curr;
		curr= (pre + curr)%m;
		pre = temp;
	}
	return curr % m;
}
int main()
{
	long long n,m;
	cin>>n>>m;
	cout<<fibonaci(n,m);
	return 0;
}
