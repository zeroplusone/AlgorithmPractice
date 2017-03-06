#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MAXN 200100
#define INF 9999999
int s[MAXN];

struct Node
{
	int lmax,rmax,mmax,sum;
	Node *l,*r;
	
	void update(int v)
	{
		val=v;
	}
	void pull()
	{	
		lmax=max(l->lmax,l->sum+r->lmax,	
	}
};

Node* build(int L,int R)
{
	Node* now=new Node();
	if(L==R)
	{
		now->update(s[L]);
		return now;
	}
	int mid=(L+R)>>1;
	now->l=build(L,mid);
	now->r=build(mid+1,R);
	
	now->pull();
	return now;
}

int query(Node* now,int L,int R,int x,int y)
{
	if(x>R || y<L)	return -INF;
	if(x<=L && y>=R)	return now->val;
	
	int mid=(L+R)>>1;
	return max( query(now->l,L,mid,x,y), query(now->r,mid+1,R,x,y));	
}


int main()
{
	int T,n,k;
	int i;
	int op,a,b;
	scanf("%d",&T);
	Node* root;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i)
			scanf("%d",&s[i]);
		for(i=1;i<k;++i)
			s[n+i]=s[i];		
		root=build(1,n+k-1);
		printf("%d\n",query(root,1,n,a,b));
	}
	return 0;
}
