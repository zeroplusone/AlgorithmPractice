#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

#define MAXN 50100
#define INF 9999999
int s[MAXN];

struct Node
{
	int valmax,valmin;
	Node *l,*r;
	
	void update(int v)
	{
		valmin=v;
        valmax=v;
	}
	void pull()
	{
		valmax=max(l->valmax,r->valmax);
	    valmin=min(l->valmin,r->valmin);
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

int querymax(Node* now,int L,int R,int x,int y)
{
	if(x>R || y<L)	return -INF;
	if(x<=L && y>=R)	return now->valmax;
	
	int mid=(L+R)>>1;
	return max( querymax(now->l,L,mid,x,y), querymax(now->r,mid+1,R,x,y));	
}

int querymin(Node* now,int L,int R,int x,int y)
{
	if(x>R || y<L)	return INF;
	if(x<=L && y>=R)	return now->valmin;
	
	int mid=(L+R)>>1;
	return min( querymin(now->l,L,mid,x,y), querymin(now->r,mid+1,R,x,y));	
}

int main()
{
	int N,Q;
	int i;
	int a,b;
	Node* root;
    memset(s,0,sizeof(s));
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;++i)
		scanf("%d",&s[i]);		
	root=build(1,N);
	while(Q--)
	{
		scanf("%d%d",&a,&b);
        printf("%d\n",querymax(root,1,N,a,b)-querymin(root,1,N,a,b));
	}
	return 0;
}
