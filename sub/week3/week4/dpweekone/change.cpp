#include <iostream>
using namespace std;

int minchange(int m)
{
	int coins[3]={1,3,4};
	int dp[m+1];
	int numcoins=0;
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		dp[i]=99999999;
		
		for(int j=0;j<3;j++)
		{
			if(i>=coins[j]){
			
			numcoins= dp[i - coins[j]]+1;
			if(numcoins < dp[i])
			{
				dp[i]=numcoins;
			}
		}
		}
	}
	return dp[m];
}

int main()
{
	int m;
	cin>>m;
	cout<<minchange(m);
	return 0;
}
