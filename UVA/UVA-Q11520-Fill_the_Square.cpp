#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
/*
#define MAX 110
char cell[MAX];
char cellm[MAX];
char AtoZ[26];
int c,n;

char fill(int num)
{
	for(char c='A';c<='Z';++c)
	{
		if(num-n>=0){if(cell[num-n]==c)continue;}				
		if(num-1>=0){if(cell[num-1]==c)continue;}
		if(num+1<=n*n){if(cell[num+1]==c)continue;}
		if(num+n<=n*n){if(cell[num+n]==c)continue;}
		return c;
	}
}

void copy(int flag)
{
	for(int i=0;i<MAX;++i)
	{
		if(flag)
			cell[i]=cellm[i];
		else
			cellm[i]=cell[i];
	}
}

int main()
{	
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{		
		scanf("%d",&n); getchar();
		printf("Case %d:\n",i);
		
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
				scanf("%c",&cell[n*j+k]);		
			getchar();
		}
		copy(0);//cellm=cell;
		char min,tmp,mem;
		//mem=cell[0];
		for(int l=0;l<26;++l)
		{
			
			cell[0]='A'+l;	min='A'+l;
			for(int j=0;j<n;++j)
			{	
				for(int k=0;k<n;++k)
				{
					if(cell[n*j+k]=='.')
					{	
						tmp=fill(n*j+k);
						if(tmp>min)
							min=tmp;
					}
				}
			}
			AtoZ[l]=min;
			copy(1); //cell=cellm
		}
		min='Z';	int m=0;	
		for(int j=25;j>=0;--j)
		{
			if(cell[n]=='A'+j)continue;		
			if(cell[1]=='A'+j)	continue;
			if(AtoZ[j]<=min)
			{
				min=AtoZ[j];
				m=j;
			}
		}
		//4
		for(int i=0;i<26;++i)
			printf("%c ",AtoZ[i]);
		cell[0]='A'+m;	
		for(int j=0;j<n;++j)
		{	
			for(int k=0;k<n;++k)
			{
				if(cell[n*j+k]=='.')
					cell[n*j+k]=fill(n*j+k);
			}
		}
			
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
				printf("%c",cell[n*j+k]);		
			printf("\n");
		}
	}
	return 0;
}
*/
//check 4 direct and fill in order 
int n;
#define MAX 110
char cell[MAX][MAX];
char solve(int x,int y)
{
	char fill='A';
	bool ok=true;
	while(fill<='Z')
	{
		ok=true;
		//left
		ok&=(y==0 || cell[x][y-1]!=fill);
		//right
		ok&=(y==n-1 || cell[x][y+1]!=fill);
		//up
		ok&=(x==0 || cell[x-1][y]!=fill);
		//down
		ok&=(y==n-1 || cell[x+1][y]!=fill);
		if(ok)	break;
		fill++;
	}
	return fill;
}

int main()
{
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{		
		scanf("%d",&n); getchar();
		printf("Case %d:\n",i);
		
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)			
				scanf("%c",&cell[j][k]);				
			getchar();
		}
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				if(cell[j][k]=='.')
					cell[j][k]=solve(j,k);
				printf("%c",cell[j][k]);	
			}
			printf("\n");
		}
	}
	return 0;
}

