#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> part(vector<int>& arr,int l,int r)
{
	int x= arr[l];
	int j=l;
	int end=r;
	int i=l;
	
	while(i <= end)
	{
		if(arr[i]<x)
		{
		   swap(arr[i],arr[j]);
		   i++;
		   j++;
		}
		else if(arr[i]>x)
		{
			swap(arr[i],arr[end]);
			end--;
		}
		else 
		{
			i++;
		}
	}
	return vector<int>{j,end};
}

void fastquicksort(vector<int>& arr,int l,int r)
{
	if(l>=r)
	return;
	
	int k= l+rand()%(r-l+1);
	swap(arr[k],arr[l]);
	
	vector<int> m = part(arr,l,r);
	int m1= m[0];
	int m2= m[1];
	fastquicksort(arr,l,m1-1);
	fastquicksort(arr,m2+1,r);
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	fastquicksort(a,0,n-1);
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
