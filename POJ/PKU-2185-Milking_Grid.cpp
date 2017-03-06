/******************
Judge   : poj
Problem : 2185-Milking Grid
Course  : Course17
discribe: find the rectangular unit of smallest area that can be repetitively tiled to make up the entire milking grid.
Input   :
		
			2 5
			ABABA
			ABABA

Output	:

			2
solve:
			KMP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXR 10010
#define MAXC 80
int pi[MAXR][MAXC];
int pi2[MAXR][MAXC];
char w[MAXR];
char in[MAXR][MAXC];
int n,m;

void buildPi(int now)
{	
	int i,j,len;
	len=strlen(w+1);
	
	pi[now][1]=0;	j=0;
	for(i=2;i<=len;++i)
	{
		while(j>0 && w[j+1]!=w[i])
		{
			j=pi[now][j];
		}

		if(w[j+1]==w[i])
			j++;
		pi[now][i]=j;

	}
}

void buildPi2(int now)
{	
	int i,j,len;
	len=strlen(w+1);
	
	pi2[1][now]=0;	j=0;
	for(i=2;i<=len;++i)
	{
		while(j>0 && w[j+1]!=w[i])
		{
			j=pi2[j][now];
		}

		if(w[j+1]==w[i])
			j++;
		pi2[i][now]=j;

	}
}

int main()
{
	int ans,i,j,k;	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0)	break;
		memset(pi,0,sizeof(pi));
		memset(pi2,0,sizeof(pi2));
		for(i=1;i<=n;++i)
		{
			getchar();
			scanf("%s",in[i]+1);
			strcpy(w+1,in[i]+1);			
			buildPi(i);
			for(j=1;j<=m;++j)
			{
				if(j%(j-pi[i][j])==0)
					pi[i][j]=j/(j-pi[i][j]);
				else
					pi[i][j]=1;
				printf("%d ",pi[i][j]);
			}
			printf("\n");
		}	
		for(i=1;i<=m;++i)
		{
			for(j=1;j<=n;++j)
			{
				w[j]=in[j][i];
			}
			w[n+1]=0;
			buildPi2(i);
			for(j=1;j<=n;++j)
			{
				if(j%(j-pi2[j][i])==0)
					pi2[j][i]=j/(j-pi2[j][i]);
				else
					pi2[j][i]=1;
			}
				
		}
		for(i=1;i<=n;++i)
		{		
			for(j=1;j<=m;++j)
			{
				printf("%d ",pi2[i][j]);
			}
			printf("\n");
		}
		
		printf("\n");
	}
	return 0;
}