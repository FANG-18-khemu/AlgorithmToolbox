#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct segment 
{
	int start ,end;
};
bool cmp(const segment i,const segment j)
{
	return i.end < j.end;
}
vector<int> optimal_points(vector<segment>& segment)
{
	sort(segment.begin(),segment.end(),cmp);
	vector<int> points;
	int point =segment[0].end;
	points.push_back(point);
	
	for(int i=1;i<segment.size();i++)
	{
		if(point <segment[i].start || point >segment[i].end)
		{
		point = segment[i].end;
		points.push_back(point);
	}}
	return points;
}

int main()
{
	int n;
	cin>>n;
	vector<segment> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].start>>arr[i].end;
	}
	vector<int> point= optimal_points(arr);
	
	cout<<point.size()<<'\n';
	
	for(int i=0;i<point.size();i++)
	   cout<<point[i]<<" ";
	   
	return 0;
}
