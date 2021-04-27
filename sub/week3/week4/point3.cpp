#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

bool compare(pair<int,char> a, pair<int,char> b){
	if(a.first!=b.first)
		return a.first<b.first;
	else
		return a.second<b.second;
	
}


int32_t main(){
	int s,p;
	cin>>s>>p;

	vector<pair<int,char>> seg;
	for(int i=0;i<s;i++){
		int a,b;
		cin>>a>>b;
		seg.push_back(pair<int,char>(a,'l'));
		seg.push_back(pair<int,char>(b,'r'));

	}
	vector<int> poi;
	
	for(int i=0;i<p;i++){
		int a;
		cin>>a;
		poi.push_back(a);
		seg.push_back(pair<int,char>(a,'p'));
	}

	sort(seg.begin(),seg.end(),compare);
	vector<int> v;
	map<int,int> m;

//	for(auto s:seg)
//		cout<<s.first<<","<<s.second<<" ";
//	cout<<endl;
	

	int c=0;
	for(auto x:seg){
		if(x.second=='l')
			c++;
		else if(x.second=='r')
			c--;
		if(x.second=='p')
			m[x.first]=c;

		}
	for(int a:poi)
		v.push_back(m[a]);

		
	

	for(int x:v)
		cout<<x<<" ";
	cout<<endl;
	

}

