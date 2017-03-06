#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define MAXN 250
int r[MAXN][MAXN];
int d[MAXN][MAXN];
int med[MAXN][MAXN];
#define INF 9999999
int sum2;
int minans;
int cost;
void find_path(int i, int j)        
{
    if (med[i][j] == -1) return; 
 
    find_path(i, med[i][j]);     
    printf("%d ",med[i][j]);
	sum2++;	cost+=r[i][med[i][j]];
    find_path(med[i][j], j);    
}

int main()
{
	int c,n,m;
	int s,t,w;
	int i,j,k;


	scanf("%d",&c);
	while(c--)
	{
		memset(r,0,sizeof(r));
		memset(d,0,sizeof(d));
		
		scanf("%d%d",&n,&m);
		
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(i==j)
					d[i][j]=0;
				else				
					d[i][j]=INF;
				med[i][j]=-1;
			}
		}
		for(i=0;i<m;++i)
		{
			scanf("%d%d%d",&s,&t,&w);
			r[s][t]=w;
			d[s][t]=w;
		}

		for(k=1;k<=n;++k)
		{
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=n;++j)
				{

					if(d[i][k]+d[k][j]<d[i][j])
					{
						d[i][j]=d[i][k]+d[k][j];
						med[i][j]=k;
					}
					
				}
			}		
		}
		
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				sum2=0;	cost=0;
				if(d[i][j]!=INF && i!=j)
				{
					printf("%d ",i);				
					find_path(i,j);
					printf("%d\n",j);
					printf("!!%d %d\n",d[i][j],sum2);
					if(sum2==n-2)
					{
						printf("~%d\n",cost);

					}
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}