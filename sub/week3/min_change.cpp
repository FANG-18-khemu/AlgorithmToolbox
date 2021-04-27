#include<iostream>
using namespace std;

int min_change(int m)
{
	int change[3]={10,5,1};
	int count=0;
	
	for(int i=0;m>0;i++)
	{
		count += m/change[i];
		m = m%change[i];
	}
	return count;
}
int main()
{
	int m;
	cin>>m;
	cout<<min_change(m);
	return 0;
}
