#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

struct DAT{
	int num;
	/*bool operator < (const DAT &b) const
	{
		return a<b.a;
	}*/
}a[200020];

/*bool cmp(const DAT &a,const DAT &b)
{
	return a.id<b.id;
}*/

struct Query{
	int l,r,bid,id;
	bool operator < (const Query &b) const
	{
		return PII(bid,r) < PII(b.bid,b.r);
	}
}Q[200020];

int cnt[100010];
ll sum;
ll ans[200020];

void add(int x)
{
	sum+=x-cnt[x];
	cnt[x]++;
}

void cut(int x)
{
	sum-=(x-cnt[x]+1);
	cnt[x]--;
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
			scanf("%d",&a[i].num);
			//a[i].id=i;
		}
		for(int i=n+1;i<=n+n;i++)
			a[i].num=a[i-n].num;
		int K=(int)sqrt(n+n);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&Q[i].l,&Q[i].r);
			if(Q[i].r<Q[i].l)
				Q[i].r+=n;
			Q[i].id=i;
			Q[i].bid=Q[i].l/K;
		}
		n=n+n;
/*for(int i=1;i<=n;i++)
	printf("%d ",a[i].num);
puts("");*/
		sort(Q,Q+m);
		fill(cnt,cnt+100010,0);
		sum=0;
		int nl,nr;
		nl=Q[0].l;
		nr=Q[0].l-1;
		for(int i=0;i<m;i++)
		{
			while(nl<Q[i].l) cut(a[nl++].num);
			while(nl>Q[i].l) add(a[--nl].num);
			while(nr<Q[i].r) add(a[++nr].num);
			while(nr>Q[i].r) cut(a[nr--].num);
			ans[Q[i].id]=sum;
//printf("%d %d %d %lld\n",i,Q[i].l,Q[i].r,sum);
		}
		for(int i=0;i<m;i++)
			printf("%lld\n",ans[i]);
	}
	return 0;
}
