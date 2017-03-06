#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct Node
{
	int color,ch_tag;
	Node *l,*r;

	int getVal()
	{
		return color|ch_tag;
	}
	void changeVal(int v)
	{
		ch_tag|=1<<(v-1);
	}
	void pull()
	{
		val=l->color|r->color;
		ch_tag=0;
	}
	void push()
	{
		l->changeVal(ch_tag);
		r->changeVal(ch_tag);
	}
};

Node* build(int L,int R)
{
	Node* now=new Node();
	if(L==R)
	{
		now->color=1;
		now->ch_tag=0;
		ch_tag=0;
		return now;
	}
	int mid=(L+R)>>1;
	now->l=build(L,mid);
	now->r=build(mid+1,R);
	
	return now;
}


void change(Node* now,int L,int R,int x,int y,int c)
{
	if(y<L || x>R)	return;
	if(x<=L && R<=y)
	{
		now->changeVal(c);
		return;
	}
	now->push();
	int mid=(L+R)>>1;
	change(now->l,L,mid,x,y,c);
	change(now->r,mid+1,R,x,y,c);
	now->pull();		
}

int query(Node* now,int L,int R,int x,int y)
{
	if(y<L || x>R)	return 0;
	if(x<=L && y>=R)return now->getVal();
	now->push();
	int mid=(L+R)>>1;
	int ans=query(now->l,L,mid,x,y)|query(now->r,mid+1,R,x,y);
	now->pull();
	return ans;
}

int countAns(int T,int num)
{
	int ans=0;
	while(T--)
		ans+=num|(1<<(T-1));
	return ans;
}

int main()
{
	int L,T,O;
	char op;
	int a,b,c;
	Node* root;
	scanf("%d%d%d",&L,&T,%O);
	
	root=build(1,L);
	
	while(O--)
	{
		getchar();
		scanf("%c",&op);
		switch(op)
		{
			case 'C':
				scanf("%d%d%d",&a,&b,&c);
				change(root,1,L,a,b,c);		
				break;
			case 'P':
				scanf("%d%d",&a,&b);
				printf("%d\n",countAns(T,query(root,1,L,a,b)));
				break;
		}
	}
	return 0;
}
