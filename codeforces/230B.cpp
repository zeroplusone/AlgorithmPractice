#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 200
double w[MAX][MAX],a[MAX][MAX],b[MAX][MAX];

int main()
{
	int n;
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)		
			for(j=0;j<n;++j)			
				scanf("%lf",&w[i][j]);
			
		for(i=0;i<n;++i)
		{
			for(j=i;j<n;++j)
			{	
				if(i==j)
				{
					a[i][j]=w[i][j];
					b[i][j]=0;
				}				
				else
				{
					a[i][j]=(w[i][j]+w[j][i])/2;
					a[j][i]=a[i][j];
					b[i][j]=(w[i][j]-w[j][i])/2;
					b[j][i]=(-1)*b[i][j];
				}
			}
		}
		
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{	
				if(j)
					printf(" ");
				printf("%.8lf",a[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{	
				if(j)
					printf(" ");
				printf("%.8lf",b[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}