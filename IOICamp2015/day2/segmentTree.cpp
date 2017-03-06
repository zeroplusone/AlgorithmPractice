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
	int val;
	Node *l,*r;
	
	void update(int v)
	{
		val=v;
	}
	void pull()
	{
		val=max(l->val,r->val);
	}
};

Node* build(int L,int R)
{
    //建立此區間的節點
	Node* now=new Node();
    //（1) 我是葉子嗎
	if(L==R)
	{
		now->update(s[L]);
		return now;
	}
	int mid=(L+R)>>1;
    // (2) 建立左子樹
	now->l=build(L,mid);
    //（3）建立右子樹
	now->r=build(mid+1,R);
	//（4）pull
	now->pull();
	return now;
}

int query(Node* now,int L,int R,int x,int y)
{
    // (1) 完全不重疊 [x y L R] or [L R x y]
	if(x>R || y<L)	return -INF;
	// (2) 完全包含 [x L R y]
    if(x<=L && y>=R)	return now->val;
	// (3) others 向左走向右走
	int mid=(L+R)>>1;
	return max( query(now->l,L,mid,x,y), query(now->r,mid+1,R,x,y));	
}

void cover(Node* now,int L,int R,int x,int v)
{
    // （1）我是葉子嗎
	if(L==R)
	{
		now->update(now->val+v);
		return;
	}
	int mid=(L+R)>>1;
    // （2）修改包含x的子樹
	if(x<=mid)
		cover(now->l,L,mid,x,v);
	else
		cover(now->r,mid+1,R,x,v);
	// （3）pull
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
