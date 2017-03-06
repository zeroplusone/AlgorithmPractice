#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MAXN 100100
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

void cover(Node* now,int L,int R,int x,int v)
{
	if(L==R)
	{
		now->update(v);
		return;
	}
	int mid=(L+R)>>1;
	if(x<=mid)
		cover(now->l,L,mid,x,v);
	else
		cover(now->r,mid+1,R,x,v);
	
	now->pull();
}

int main()
{
	int T,n,m;
	int i;
	int op,a,b;
	scanf("%d",&T);
	Node* root;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)
			scanf("%d",&s[i]);		
		root=build(1,n);
		while(m--)
		{
			scanf("%d%d%d",&op,&a,&b);
			if(op==1)			
				printf("%d\n",query(root,1,n,a,b));
						
			else if(op==2)
				cover(root,1,n,a,b);
				
		}
	}
	return 0;
}
