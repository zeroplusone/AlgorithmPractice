#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 25
int m[MAXN][MAXN];
int dis[MAXN][MAXN];
int n;
void Floyd()
{
	int i,j,k;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(i==j)	dis[i][j]=0;
			if(m[i][j]==0)	dis[i][j]=999999;
			else	dis[i][j]=m[i][j];
		}
	}
	for(k=0;k<n;++k)
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
}
int main()
{

	int i,j;
	int a,b,c,d;
	bool aya=false;
	int deg;
	while(scanf("%d",&n)!=EOF)
	{
		a=0;	b=0;	c=999999;
		for(i=0;i<n;++i)
		{
			aya=false;
			deg=0;
			for(j=0;j<n;++j)
			{
				scanf("%d",&m[i][j]);

				if( m[i][j]==1)
				{
					aya=true;
					deg++;
					if(j>i)
						b++;
				}

			}
			if(aya)	a++;
			c=deg<c?deg:c;
		}
		d=0;
		Floyd();
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				deg=dis[i][j];
				d=d<deg?deg:d;
			}
		}

		printf("%d %d %d %d\n",a,b,c,d);
	}
	return 0;
}
