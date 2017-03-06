#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 100010

struct station
{
	int x;
	int y;
	bool operator<(const station& s)const
	{
		return x==s.x?y<s.y:x<s.x; 
	}
}sta[MAX];

struct agent
{
	int x;
	int y;
	bool operator<(const station& s)const
	{
		return x==s.x?y<s.y:x<s.x; 
	}
}age[MAX];

int t,n;

int findmin(int p)
{
	for()
}

int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		//read
		scanf("%d",&n);		
		for(int j=0;j<n;++j)
			scanf("%d %d",&sta[j].x,&sta[j].y);
		for(int j=0;j<n;++j)
			scanf("%d %d",&age[j].x,&age[j].y);
		//compare
		int minpoint;
		sort(age,age+n);
		for(int j=0;j<n;++j)
		{
			minpoint=findmin(j);
		}
			
		
	}
}