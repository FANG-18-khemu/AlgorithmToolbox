#include <iostream>
#include <vector>
using namespace std;
void getnumber(vector<int>& num,int n)
{
	int point=1;
	for(int i =1 ;i<=n;i++){
		n= n-i;
		if(n<=i)
		{
			num.push_back(n+i);
		}
		else if(n==0)
		{
			num.push_back(i);
			break;
		}
		else 
		{
			num.push_back(i);
		}
	}

}
int main()
{
	int n;
	cin>>n;
	vector<int> num;
	getnumber(num,n);
	cout<<num.size()<<"\n";
	for(int i =0;i<num.size();i++)
	  cout<<num[i]<<" ";
	return 0;
}
