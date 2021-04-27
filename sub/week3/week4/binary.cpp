#include <iostream>
#include  <vector>
using namespace std;

long long binary(vector<int>& arr,int ans)
{
	int l=0;
	int r=arr.size() -1;
	//cout<<r<<" <-- ";
	
	while(l<=r)
	{
		int mid = l + (r-l)/2;
		
		if(arr[mid]==ans)
		return mid;
		else if (arr[mid] < ans)
		  l=mid +1;
		else 
		  r=mid-1;  
	}
	return -1;
}
int main()
{
	int n,m;
	cin>>n;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++)
	   cin>>a[i];
	   
  cin>>m;
	vector<int> find(m);
	for(int i=0;i<m;i++)
	  cin>>find[i];
	  
	for(int i=0;i<m;i++)
	  cout<<binary(a,find[i])<<" ";   
}
