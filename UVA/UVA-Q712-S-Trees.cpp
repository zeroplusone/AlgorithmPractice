/******************
Judge   : UVA
Problem : 712 - S-Trees
Course  : Course6
discribe: binary tree representing a Boolean function
Input   : 	3			//n
			x1 x2 x3	//level seqence
			00000111	//terminal node
			4			//m
			000			//question
			010
			111
			110
			===============
			3
			x3 x1 x2
			00010011
			4
			000
			010
			111
			110
			================
			0
Output  : 	S-Tree #1:
			0011
			\n
			S-Tree #2:
			0011
			\n
Solve   :	binary tree
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 10
int x[MAXN];
int q[MAXN];
int tree[1000];

int power(int k)
{
	int ans=1;
	for(int i=0;i<k;++i)
		ans*=2;
	return ans;
}

int main()
{
	int n,m,ans,tmp;
	int i,num=1;
	while(scanf("%d\n",&n)!=EOF)
	{		
		if(n==0)	break;

		for(i=0;i<n;++i)
		{
			getchar();
			x[i]=getchar()-'0';
			getchar();
		}
		tmp=power(n);
		for(i=0;i<tmp;++i)
		{
			tree[i]=getchar()-'0';
		}
		scanf("%d\n",&m);
		printf("S-Tree #%d:\n",num++);
		while(m--)
		{
			for(i=1;i<=n;++i)			
				q[i]=getchar()-'0';
			
			getchar();
			ans=1;
			for(i=0;i<n;++i)
			{
				if(q[x[i]]==0)
					ans*=2;
				else
					ans=ans*2+1;				
			}
			ans-=tmp;
			printf("%d",tree[ans]);				
		}
		printf("\n\n");
	}
	return 0;
}