#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

struct DAT{
	int a,num,id;
	bool operator < (const DAT &b) const
	{
		return a<b.a;
	}
}a[100020];

bool cmp(const DAT &a,const DAT &b)
{
	return a.id<b.id;
}

struct Query{
	int l,r,bid,id;
	bool operator < (const Query &b) const
	{
		return PII(bid,r) < PII(b.bid,b.r);
	}
}Q[100020];

int cnt[100000];
int MAX;
int ans[100020];

void add(int x)
{
	int now=++cnt[x];
	if(now==1)
		MAX++;
}

void cut(int x)
{
	int now=--cnt[x];
	if(now==0)
		MAX--;
}

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].a);
			a[i].id=i;
		}
		sort(a+1,a+n+1);
		int tmp=0;
		a[1].num=tmp;
		for(int i=2;i<=n;i++)
		{
			if(a[i].a!=a[i-1].a)
				a[i].num=++tmp;
			else
				a[i].num=tmp;
		}
		sort(a+1,a+n+1,cmp);
		int K=(int)sqrt(n);
//printf("%d\n",K);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&Q[i].l,&Q[i].r);
			Q[i].id=i;
			Q[i].bid=Q[i].l/K;
//printf("%d:%d\n",i,Q[i].bid);
//printf("(%d,%d)\n",Q[i].l,Q[i].r);
		}
		sort(Q,Q+m);
		fill(cnt,cnt+tmp+1,0);
		MAX=0;
		int nl,nr;
		nl=Q[0].l;
		nr=Q[0].l-1;
//puts("!");
		for(int i=0;i<m;i++)
		{
//printf("(%d,%d)\n",Q[i].l,Q[i].r);
			while(nl<Q[i].l) cut(a[nl++].num);
			while(nl>Q[i].l) add(a[--nl].num);
			while(nr<Q[i].r) add(a[++nr].num);
			while(nr>Q[i].r) cut(a[nr--].num);
			ans[Q[i].id]=MAX;
		}
		for(int i=0;i<m;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
