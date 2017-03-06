#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 100010

struct xpx
{
	long int num,t,d;
	int yes;
	bool operator<(const xpx &p)const
	{
		return num<p.num;
	}
}x[MAX];

void reset(long int nn)
{
	for(long int i=0;i<nn;++i)
	{
		x[i].num=-1;
		x[i].t=0;
		x[i].d=0;
		x[i].yes=1;
	}
}

int main()
{
	long int n,in,now,j,de;
	bool hit=false;
	while(scanf("%ld",&n)!=EOF)
	{
		now=0;	de=0;
		reset(n);
		for(long int i=0;i<n;++i)
		{
			hit=false;
			scanf("%ld",&in);
			for(j=0;j<now;++j)
			{
				if(x[j].num==in)
				{
					hit=true;
					break;
				}
				else
					continue;
			}
			if(hit)
			{
				if(x[j].d==0)
				{
					x[j].d=i-x[j].t;
					x[j].t=i;
				}
				else
				{
					//printf("ya %d %d %d\n",i-x[j].t,x[j].d,x[j].yes);
					if(x[j].yes==1 && i-x[j].t!=x[j].d)
					{//printf("ya\n");
						x[j].yes=0;de++;
					}
					else
					{
						x[j].t=i;
					}
				}
			}
			else
			{
				x[now].num=in;
				x[now].t=i;
				now++;
			}
		}
		sort(x,x+now);
		printf("%ld\n",now-de);
		for(long int i=0;i<now;++i)
		{
			if(x[i].yes==1)
				printf("%ld %ld\n",x[i].num,x[i].d);
			
				
		}
	}
	return 0;
}