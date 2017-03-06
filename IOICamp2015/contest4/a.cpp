#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

#define INF 100100
#define MAXN 1100

int n;

struct castle
{
	int w,c;
	bool operator<(const castle &p)const
	{
		return (c-w)>(p.c-p.w);
	}
}ca[MAXN];

bool canbe(int mid)
{
	int sum=0,cost=0,i,j;
	for(i=0;i<n;++i)
	{
		if(sum+ca[i].w<=mid)
			sum+=ca[i].w;
		else
			break;
	}
	for(j=i;j<n;++j)
		cost+=ca[j].c;
	if(cost<=sum)	return true;
	else	return false;
}

int binary_search(int L,int R)
{
	int mid;
	while(L<R)
	{
		//printf("!%d\n",mid);
		mid=(L+R)>>1;
		if(canbe(mid))
		{
			R=mid;
			
		}
		else
		{
			L=mid+1;			
		}
	}
}

int main()
{
	int T;
	int i;
	int L,R;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		L=INF;	R=0;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&ca[i].w,&ca[i].c);
			L=L>ca[i].c?ca[i].c:L;
			R+=ca[i].w;
		}
		sort(ca,ca+n);
		//printf("%d %d\n",ca[0].w,ca[0].c);	
		printf("%d\n",binary_search(L,R));
	}
	return 0;
}


