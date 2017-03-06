#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define INF 1000100
#define MAXN 1100
int p[MAXN];

int main()
{
	int T;
	int i,j,d,u,len,n,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);

		for(i=1;i<=n;++i)
		{
			scanf("%d %d",&p[i],&d);
			tmp=INF;
			for(j=0;j<d;++j)
			{
				scanf("%d",&u);
				tmp=tmp>p[u]?p[u]:tmp;
			}			
			if(tmp!=INF)
				p[i]+=tmp;
		}
/*
		for(i=0;i<len;++i)
		{
			memset(v,false,sizeof(v));
//			printf("@%d\n",s[i]);
			dfs(n,s[i],0,pn[i]);
			//ans=ans>dis[n]+pn[i]?dis[n]+pn[i]:ans;
		}
*/
		printf("%d\n",p[n]);
	}
	return 0;
}
