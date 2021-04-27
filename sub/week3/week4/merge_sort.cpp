#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& a,vector<int>& b,int l,int mid,int r)
{
	int inversioncount=0;
	int i=l;
	int j=mid+1;
	int k=l;
	
	while(i<= mid && j <= r)
	{
		if(a[i]<=a[j])
		{
			b[k++]=a[i++];
		}else 
		{
			b[k++]=a[j++];
			inversioncount += (mid -i+1);
		}
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	for(int i=l;i<=r;i++)
	{
		a[i]= b[i];
	}
	return inversioncount;
}

long long mergesort(vector<int>& a,vector<int>& b, int l,int r)
{
	long long inversioncount = 0;
	
	if( l >=r)
	{
	return 0;
	}
	int mid = l + (r-l)/2;
	
	inversioncount += mergesort(a,b,l,mid);
	inversioncount += mergesort(a,b,mid+1,r);
	
	inversioncount += merge(a,b,l,mid,r);

	return inversioncount;
}


int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	 cin>>a[i];
	 
	vector<int> b=a;
	cout<<mergesort(a,b,0,n-1);

	return 0;
}
