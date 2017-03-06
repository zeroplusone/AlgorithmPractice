#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

struct Treap{
	int size;
	ll sum,val;
	Treap *l,*r;
	Treap() {}
	Treap(ll val_): size(1), sum(val_), val(val_), l(0), r(0) {}
}space[200000],*at;

bool choose(int a,int b)
{
	return rand()%(a+b)<a;
}
int size(Treap *p)
{
	return p?p->size:0;
}
ll sum(Treap *p)
{
	return p?p->sum:0;
}
void push(Treap *p) {}
void pull(Treap *p)
{
	p->size = size(p->l) + size(p->r) +1;
	p-> sum =  sum(p->l) +  sum(p->r) + p->val;
}

Treap* merge(Treap *a,Treap *b)
{
	if(!a || !b) return a?a:b;
	if(choose( size(a),size(b) ))
	{
		push(a);
		a->r = merge(a->r,b);
		pull(a);
		return a;
	}
	else
	{
		push(b);
		b->l = merge(a,b->l);
		pull(b);
		return b;
	}
}

void split(Treap *t,Treap* &a,Treap* &b,int k)
{
	if(!t)
	{
		a=b=0;
		return;
	}
	push(t);
	if(t->val <= k)
	{
		a=t;
		split(t->r,a->r,b,k);
		pull(a);
	}
	else
	{
		b=t;
		split(t->l,a,b->l,k);
		pull(b);
	}
}

void insert(Treap* &t,Treap *in)
{
	Treap *tl,*tr;
	split(t,tl,tr,in->val);
	t=merge(tl, merge(in,tr) );
}

/*void print(Treap *p)
{
	if(!p) return;
	print(p->l);
	printf("%d ",p->val);
	print(p->r);
}*/

vector<Treap*> vt;
void DFS(Treap *p)
{
	if(!p)
		return;
	DFS(p->l);
	DFS(p->r);
	p->l = p->r = 0;
	p->size = 1;
	p->sum = p->val;
	vt.pb(p);
}
void Merge(Treap* &a,Treap* &b)
{
	if(size(a) < size(b) )
		swap(a,b);
	vt.clear();
	DFS(b);
	for(Treap* i:vt)
	{
		insert(a,i);
	}
}

ll L[100010];
VI e[100010];
Treap* st[100010];

int main()
{
	int T,N,M,P,C;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		at=space;
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++)
			e[i].clear();
		for(int i=1;i<=N;i++)
		{
			scanf("%d%d%lld",&P,&C,L+i);
			st[i]=new (at++) Treap(C);
			e[P].pb(i);
		}
		for(int i=N;i>=1;i--)
		{
			for(int to:e[i])
				Merge(st[i],st[to]);
			int l=0,r=M,m;
			Treap *tl,*tm,*tr;
			while(l<=r)
			{
				m=(l+r)/2;
				split(st[i],tl,tr,m);
				if(sum(tl)<=M)
					l=m+1;
				else
					r=m-1;
				st[i]=merge(tl,tr);
			}
//print(st[i]);
			split(st[i],tl,tr,l);
			split(tl,tl,tm,r);
			ll tmp=M-sum(tl);
			ans=max(ans, L[i] * ( size(tl) + min((ll)size(tm) , tmp/l) )  );
			
/*printf("%d:(%lld)(%lld)%lld\n",i, size(tl) + max((ll)size(tm) ,
L[i] * ( size(tl) + max((ll)size(tm) , tmp/l) ), tmp/l),ans);*/
/*printf("l=%d  size=%d %d %d %lld\n",l,size(tl),size(tm),size(tr),sum(tl));
printf("%d:(%lld)(%lld)%lld\n\n",i, size(tl) + min((ll)size(tm) , tmp/l) ,
L[i] * ( size(tl) + min((ll)size(tm) , tmp/l) ),ans);*/

			st[i]=merge( tl, merge(tm,tr) );
		}
		printf("%lld\n",ans);
	}
	return 0;
}
