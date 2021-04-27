#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majority(vector<int>& arr,int left,int right)
{
	if(left ==right)
	   return -1;
	if(left +1 ==right)
	   return arr[left];
	   
	sort(arr.begin(),arr.end());
	
	int count=0;
	int mid = left + (right -left)/2;
	int ans= arr[mid];
	
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]==ans)
		 {
		 	count++;
		 }
	}
	
	if(count > arr.size()/2)
	  return 1;
	  
	
	return -1;	
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	
	for(int i=0;i<a.size();i++)
	  cin>>a[i];
	
	cout<<(majority(a,0,a.size()-1) !=-1)<<"\n";  
	return 0;
}
