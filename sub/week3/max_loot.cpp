#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct item 
{
   int val;
   int weight;
   	
};

bool cmp(const item a,const item b)
{
	double r1= (double)a.val/(double)a.weight;
	double r2= (double)b.val/ (double)b.weight;
	return r1 > r2; 
}

double freactionalknap(int W,int n,item arr[])
{
	sort(arr,arr+n,cmp);
	
	int totalweight=0;
	double finalval=0.0;
	
	for(int i=0;i<n;i++)
	{
		if(totalweight + arr[i].weight <=W)
		{
			finalval+= arr[i].val;
			totalweight += arr[i].weight;
		}
		else{
			int remain = W - totalweight;
			finalval += remain*((double)arr[i].val/(double)arr[i].weight);
			break;
		}
	}
	return finalval;
}


int main()
{
	int n,W;
	cin>>n>>W;
	
	item arr[n];
	for(int i =0;i<n;i++)
	{
		cin>>arr[i].val;
		cin>>arr[i].weight;
	}

	cout<<fixed<<setprecision(4)<<freactionalknap(W,n,arr);
}



