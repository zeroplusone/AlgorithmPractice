#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 150
int r[MAX][MAX],n;
//bool d[MAX][MAX];
void reset()
{
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			r[i][j]=0;
	//memset(d,true,sizeof(d));
}

void print()
{
/*
for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			
			printf("%d ",r[i][j]);
		}
		printf("\n");
	}
*/
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(r[i][j]!=0)
				printf("%d %d %d\n",i,j,r[i][j]);
		}
	}
}

int main()
{
	int c,m;
	bool bye;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{
		if(i!=1)
			printf("\n");
		scanf("%d",&n);
		m=n*(n-1)/2;
		reset();	bye=false;
		for(int j=1;j<n;++j)
		{
			for(int k=1;k<=j;++k)
			{
				scanf("%d",&r[j+1][k]);
				r[k][j+1]=r[j+1][k];
			}
		}
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				for(int l=1;l<=n;++l)
				{
					if(j!=k && k!=l && j!=l && r[k][l]!=0 && r[k][j]!=0 && r[j][l]!=0)
					{
						if(r[k][j]+r[j][l]==r[k][l])
						{
							m--;
							r[k][l]=r[l][k]=0;
						}
						else if(r[k][j]+r[j][l]<r[k][l])
						{	
							bye=true;							
							break;
						}
						
					}
				}
				if(bye)	break;
			}
			if(bye)	break;
		}
		
		printf("Case #%d:\n",i);
		if(bye)
			printf("Need better measurements.\n");
		else
		{
			printf("%d\n",m);
			print();
		}
		
	}
	return 0;
}