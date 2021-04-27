#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
long long slowproduct(const vector<int>& num)
{
	long long result=0;
	for(int i=0;i<num.size();i++)
	{ 
		for(int j=i+1;j<num.size();j++)
		{
			if(num[i]*num[j] >result)
			   result=num[i]*num[j];
		}
	}
	
	return result;
}
long long fastproduct(const vector<int>& num)
{
	int max1_index=-1;
	int max2_index=-1;
	for(int i=0;i<num.size();i++)
	{
		if(max1_index==-1 || num[i]>num[max1_index])
		max1_index=i; 
	}
	
	for(int j=0;j<num.size();j++)
	{
		if((j!=max1_index) && (max2_index ==-1 || num[j] > num[max2_index]))
		    max2_index= j;
	}
	
	return (long long)(num[max1_index])*num[max2_index];
}

int main()
{
	/*
	while(true)
	{
		int n = rand()%10 +2;
		vector<int> num(n);
		for(int i=0;i<n;i++)
		   num[i]= (rand()%10);
		for(int i=0;i<n;i++)
		   cout<<num[i]<<" ";
		long long res1,res2;
		res1= slowproduct(num);
		res2= fastproduct(num);
		if(res1 != res2)
		{
			cout<<"wrong answer";
			break;
		}
		else
		{
			cout<<"correct\n";
		}
	}
	*/
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	   cin>>a[i];
	   
	long long result = fastproduct(a);
	cout<<result;   
	return 0;
}
