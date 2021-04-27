#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp_sequence(int n)
{
	vector<int> dp={0};
	vector<int> operation={1};
	vector<int> sequence;
	
	if(n==1)
	{
		sequence.push_back(1);
		return sequence;
	}
	
	for(int i=2;i<=n;i++)
	{
		int res1=INT_MAX;
		int res2=INT_MAX;
		int res3=INT_MAX;
		
		res1=dp[i-2];
		if(i%2==0)
		{
			res2=dp[(i/2)-1];
		}
		if(i%3==0)
		{
			res3=dp[(i/3)-1];
		}
		
		if(res3<= res1 && res3<=res2)
		{
			operation.push_back(3);
			dp.push_back((res3+1));
		}
		else if(res2 <= res3 && res2<=res1)
		{
			operation.push_back(2);
			dp.push_back(res2+1);
		}
		else if(res1<= res3 && res1<=res2)
		{
			operation.push_back(1);
			dp.push_back(res1+1);
		}
	}
	
	int i=n;
	while(i>=1)
	{
		sequence.push_back(i);
		if(operation[i-1]==1)
		{
			i-=1;
		}
		else if(operation[i-1]==2)
		{
			i/=2;
		}
		else 
		{
			i/=3;
		}
	}
	reverse(sequence.begin(),sequence.end());
	return sequence;
}

int main()
{
	int n;
	cin>>n;
	vector<int> sequence = dp_sequence(n);
	cout<<sequence.size()-1<<"\n";
	for(int i=0;i<sequence.size();i++)
	{
		cout<<sequence[i]<<" ";
	}
	return 0;
}
