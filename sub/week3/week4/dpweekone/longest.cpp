#include <iostream>
#include <vector>

using namespace std;

int logest_common_subsequence(vector<long long>& num1,vector<long long>& num2)
{
	int l1= num1.size();
	int l2= num2.size();
	
vector<vector<long long> > dp(l1+ 1, vector<long long>(l2 + 1, 0));

	
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(num1[i-1]==num2[j-1])
			{
				dp[i][j] = 1+ dp[i-1][j-1];
			}
			else
			{
				dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[l1][l2];
}

int main()
{
	int n;
	cin>>n;
	vector<long long> num1(n);
	for(int i=0;i<n;i++)
	    cin>>num1[i];
	
	int m;
	cin>>m;
	vector<long long> num2(m);
	for(int j=0;j<m;j++)
	  cin>>num2[j];
	  
	cout<<logest_common_subsequence(num1,num2);      
	return 0;
}
