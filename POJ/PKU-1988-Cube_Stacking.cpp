#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 35000
int p[MAX];
int num[MAX];
int under[MAX];

void makeset(int x)
{
	p[x]=x;
	num[x]=1;
	under[x]=0;
}

int findset(int x)
{
	int t=p[x];
	if(x!=p[x])
	{
		
		p[x]=findset(p[x]);
		under[x]+=under[t];
	}
	return p[x];
}

void link(int x,int y)
{
	if(x==y)	return;

	p[x]=y;
	under[x]+=num[y];
	num[y]+=num[x];
		
}

int main()
{
	int c,a,b;
	int i;
	char in;
	scanf("%d",&c);
	
		for(i=0;i<MAX;++i)	
			makeset(i);
		while(c--)
		{
			cin>>in;
			switch(in)
			{
				case 'M':
					scanf("%d %d",&a,&b);
					link(findset(a),findset(b));
					break;
				case 'C':
					scanf("%d",&a);
					findset(a);
					printf("%d\n",under[a]);
					break;
				default:
					break;
			}
		}
	
	return 0;	
}

