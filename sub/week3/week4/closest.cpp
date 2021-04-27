#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

struct point
{
	public:
    	long long x;
    	long long y;
};

int cmpx(const void* a,const void* b)
{
	point *p1 = (point *)a;
	point *p2 = (point *)b;
	return (p1->x - p2->x);
}

int cmpy(const void* a, const void* b)
{
	point *p1= (point *)a;
	point *p2= (point *)b;
	return (p1->y - p2->y);
}

double dist(point p1,point p2)
{
	return sqrt((p1.x -p2.x)*(p1.x -p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double bruteforce(point p[],int n)
{
	double min= 9999999999.99;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(dist(p[i],p[j])<min)
			{
				min= dist(p[i],p[j]);
			}
		}
	}
	return min;
}

long long min(float x,float y)
{
	return (x<y)? x :y;
}

double stripclosest(point strip[],int size,double d)
{
	double min=d;
	qsort(strip,size,sizeof(point),cmpy);
	
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size && (strip[j].y - strip[i].y < min);j++)
		{
			if(dist(strip[i],strip[j]) < min)
			{
				min= dist(strip[i],strip[j]);
			}
		}
	}
	return min;
}

double closestutil(point p[],int n)
{
	if(n<=3)
	  return bruteforce(p,n);
	  
	  int mid = n/2;
	  point midpoint = p[mid];
	  double dl = closestutil(p,mid);
	  double dr = closestutil(p+mid,n-mid);
	  
	  double d = min(dl,dr);
	  
	  point strip[n];
	  int j=0;
	  for(int i=0;i<n;i++)
	  {
	  	if(abs(p[i].x - midpoint.x) < d)
	  	{
	  		strip[j]=p[i];
	  		j++;
		  }
	  }
	  return min(d,stripclosest(strip,j,d));
}

double smallestdist(point p[],long long n)
{
	qsort(p,n,sizeof(point),cmpx);
	return closestutil(p,n);
}

int main()
{
	long long n;
	cin>>n;
	point arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].x>>arr[i].y;
	}
	cout<<fixed<<setprecision(9)<<smallestdist(arr,n);
	return 0;
}
