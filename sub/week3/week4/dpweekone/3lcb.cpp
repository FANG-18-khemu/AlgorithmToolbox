#include <iostream>
#include <vector>

using namespace std;

int lcb(vector<int>& a,vector<int>& b,vector<int>& c)
{
	int l1=a.size();
	int l2=b.size();
	int l3=c.size();
	vector<vector<vector<long long> > > dp(l1+1 ,vector<vector<long long> >(l2+1,vector<long long>(l3+1,0)));
     
     for(int i=1;i<=l1;i++)
     {
     	for(int j=1;j<=l2;j++)
     	{
     		for(int k=1;k<=l3;k++)
     		{
     			if(a[i-1] == b[j-1] && b[j-1]==c[k-1])
     			{
     				dp[i][j][k]= 1 + dp[i-1][j-1][k-1];
				 }
				 else 
				 {
				 	dp[i][j][k]= max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
				 }
			 }
		 }
	 }
     
    return dp[l1][l2][l3];
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
	int m;
	cin>>m;
	vector<int> b(m);
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	int g;
	cin>>g;
	vector<int> c(g);
	for(int i=0;i<g;i++)
	{
		cin>>c[i];
	}
	
	cout<<lcb(a,b,c)<<endl;
	return 0;
}
