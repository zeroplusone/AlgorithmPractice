#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAXN 110
int n;
int score[5];
struct player
{
	double fs;
	int id;
	bool operator<(const player p)const
	{
		return fs==p.fs?id<p.id:fs>p.fs;
	}
}ps[MAXN];

int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(j=0;j<n;++j)
		{
			for(i=0;i<5;++i)
			{
				scanf("%d",&score[i]);
			}
			ps[j].fs=(score[1]+score[2])*0.3+(score[3]+score[4])*0.2;
			ps[j].id=j+1;
		}
		sort(ps,ps+n);
		if(n<=3)
		{
			printf("%d%c",ps[0].id,'\n');
		}
		else
		{
			for(j=0;j<3;++j)
			{
				printf("%d%c",ps[j].id,j==2?'\n':' ');
			}
		}
	}
	return 0;
}