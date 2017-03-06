/******************
Judge   : POJ
Problem : PKU-1328-Radar_Installation
Course  : Course3
discribe: . find the minimal number of radar installations to cover all the islands.
			radar on x-axis,island above x-axis
Input   :
			3 2	//n (#island) d(radar dis)
			1 2	//pos
			-3 1
			2 1

			1 2	//n d
			0 2

			0 0	//end

Output	:
			Case 1: 2
			Case 2: 1
solve:
		greedy
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXN 1100

struct island
{
	double x,y;
	double sx,ex;
	/*bool operator<(const island &p)const
	{
		return ex==p.ex?sx>p.sx:ex<p.ex;
	}*/
}range[MAXN];

bool cmp(island a,island b)
{
	if(a.ex==b.ex)
		return a.sx>b.sx;
	else
		return a.ex<b.ex;
}

int main()
{
	int n;
	double d,len;
	int i;
	int ans;
	int casenum=1;
	int now;
	while(scanf("%d%lf",&n,&d)!=EOF)
	{
		if(n==0 && d==0)	break;
		if(d<0)
			ans=-1;
		else
		{
			ans=0;
			for(i=0;i<n;++i)
			{
				scanf("%lf%lf",&range[i].x,&range[i].y);
				if(range[i].y>d)	ans=-1;
				len=range[i].x-(sqrt(d*d-range[i].y*range[i].y));
				range[i].sx=range[i].x-len;
				range[i].ex=range[i].x+len;
				
			}
			if(ans!=-1)
			{
				//greedy
				sort(range,range+n,cmp);
				now=n-1;	ans=1;
				for(i=n-2;i>=0;--i)
				{
					if(range[i].ex<range[now].sx)
					{
						now=i;
						ans++;
					}
				}
			}
		}
		printf("Case %d: %d\n",casenum++,ans);

	}
	return 0;
}
