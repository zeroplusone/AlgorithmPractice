#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define MAX 150
#define MIN -1300000
int m[MAX][MAX];
int sum[MAX][MAX];
int n;

int main()
{
	int a,b,max,plus;
	while(scanf("%d",&n)!=EOF)
	{
		max=MIN;
		
		for(int i=0;i<n*n;++i)
		{
			a=i/n;
			b=i%n;
			scanf("%d",&m[a][b]);
			sum[a][b]=b==0?0+m[a][b]:sum[a][b-1]+m[a][b];
			//printf("%d ",sum[a][b]);
			//if(b==n-1)	printf("\n");
		}
		
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				for(int k=0;k<n;++k)
				{
					for(int l=0;l<=k;++l)
					{
						plus=0;
						for(int m=l;m<=k;++m)
							plus+=j==0||i==j?sum[m][i]:sum[m][i]-sum[m][j];
						if(plus>max)
								max=plus;	
						//printf("%d %d %d %d %d\n",i,j,k,l,plus);
					}
				}
			}
		}
		printf("%d\n",max);
		
	}
	return 0;
}