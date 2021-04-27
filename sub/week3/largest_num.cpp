#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string first, string second)
{
	string one = first + second;
	string two = second + first;
	int i=0;
	while(one[i] && two[i])
	{
		if(one[i]>two[i])
		  return true;
		else if(one[i]<two[i])
	      return false;
	
	  ++i;
	}
	return false;
}

void largest(vector<string>& arr,int n)
{
	sort(arr.begin(),arr.end(),cmp);
	
	for(int i=0;i<n;i++)
	  cout<<arr[i];
	
	  
}

int main()
{
	int n;
	cin>>n;
	vector<string> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	largest(arr,n);
	return 0;
}
