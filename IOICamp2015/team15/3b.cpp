#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

struct Dis{
	int f[10010];
	void init(int n)
	{
		for(int i=1;i<=n;i++)
			f[i]=i;
	}
	int find(int a)
	{
		if(f[a]==a)
			return a;
		return f[a]=find(f[a]);
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
	void Union(int a,int b)
	{
		//if(!same(a,b))
		//printf("%d,%d\n",find(a),find(b));
		f[find(a)] = find(b);
		//printf("%d,%d\n",a,b);
	}
}dis;

struct E{
	int u,v,w;
	bool operator < (const E &b)const
	{
		return w<b.w;
	}
}e[30010];


int main()
{
	int T,N,M;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		dis.init(N);
		for(int i=0;i<M;i++)
			scanf("%d%d%d",&e[i].u, &e[i].v, &e[i].w);
		int ans=0;
		bool yes=1;
		sort(e,e+M);
		//dis.
//puts("@@");
		for(int i=0;i<M;i++)
		{
//	printf("%d\n",i);
			if(!dis.same(e[i].u, e[i].v))
			{
//	printf("%d\n",i);
				ans=max(ans,e[i].w);
				dis.Union(e[i].u, e[i].v);
			}
		}
//puts("~");
		int tmp=dis.find(1);
		for(int i=2;i<=N;i++)
			if(dis.find(i)!=tmp)
				yes=0;
		if(yes)
			printf("%d\n",ans);
		else
			puts("Earth Worm QAQ");
	}
	return 0;
}
