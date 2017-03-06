/******************
Judge   : UVA
Problem : 989-SuDoku.cpp
Course  : Course7
discribe: solve a sudoku
Input   : 	3     // 1~n*n
			0 6 0 1 0 4 0 5 0
			0 0 8 3 0 5 6 0 0
			2 0 0 0 0 0 0 0 1
			8 0 0 4 0 7 0 0 6
			0 0 6 0 0 0 3 0 0
			7 0 0 9 0 1 0 0 4
			5 0 0 0 0 0 0 0 2
			0 0 7 2 0 6 9 0 0
			0 4 0 5 0 8 0 7 0
Output  :	9 6 3 1 7 4 2 5 8 //¼Æ¿W¶ñµª®×
			1 7 8 3 2 5 6 4 9
			2 5 4 6 8 9 7 3 1
			8 2 1 4 3 7 5 9 6
			4 9 6 8 5 2 3 1 7
			7 3 5 9 6 1 8 2 4
			5 8 9 7 1 3 4 6 2
			3 1 7 2 4 6 9 8 5
			6 4 2 5 9 8 1 7 3
Solve   : :backtrack
*******************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 12
int num,n;
int s[MAX][MAX];
bool usedr[MAX][MAX];
bool usedc[MAX][MAX];
bool useds[MAX][MAX];
bool changeline;
bool ya;

void reset()
{
	memset(usedr,false,sizeof(usedr));
	memset(usedc,false,sizeof(usedc));
	memset(useds,false,sizeof(useds));
	ya=false;
}

void print()
{
	if(!changeline)
		changeline=true;
	else
		printf("\n");
	for(int i=0;i<num;++i)
	{
		for(int j=0;j<num;++j)
		{
			if(j==0)
				printf("%d",s[i][j]);
			else
				printf(" %d",s[i][j]);
		}
		printf("\n");
	}
	/*printf("\n");
	for(int i=0;i<num;++i)
	{
		for(int j=1;j<=num;++j)
		{
			if(j==0)
				printf("%d",usedr[i][j]);
			else
				printf(" %d",usedr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<num;++i)
	{
		for(int j=1;j<=num;++j)
		{
			if(j==0)
				printf("%d",usedc[i][j]);
			else
				printf(" %d",usedc[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<num;++i)
	{
		for(int j=1;j<=num;++j)
		{
			if(j==0)
				printf("%d",useds[i][j]);
			else
				printf(" %d",useds[i][j]);
		}
		printf("\n");
	}*/
}

void backtrack(int fill)
{
	//printf("$%d\n",fill);
	//print();
	if(fill==num*num)
	{	
		ya=true;
		print();
		return;
	}
	if(s[fill/num][fill%num]==0)
	{
		for(int i=1;i<=num;++i)
		{
			//printf("!%d %d %d %d\n",i,usedr[fill/num][i],usedc[fill%num][i],useds[n*((fill/num)/n)+((fill%num)/n)][i]);
			if(!usedr[fill/num][i] && !usedc[fill%num][i] && !useds[n*((fill/num)/n)+((fill%num)/n)][i])
			{	
				s[fill/num][fill%num]=i;
				usedr[fill/num][i]=true;
				usedc[fill%num][i]=true;
				useds[n*((fill/num)/n)+((fill%num)/n)][i]=true;
				//printf("@%d\n",n*((fill/num)/n)+((fill%num)/n));print();
				backtrack(fill+1);
				if(ya)
					return;
				//printf("%d back\n",fill);
				s[fill/num][fill%num]=0;
				usedr[fill/num][i]=false;
				usedc[fill%num][i]=false;
				useds[n*((fill/num)/n)+((fill%num)/n)][i]=false;
				//printf("#\n");print();
			}
		}
	}
	else
		backtrack(fill+1);
}

int main()
{
	
	changeline=false;
	while(scanf("%d",&n)!=EOF)
	{		
		reset();
		num=n*n;	
		for(int i=0;i<num;++i)
		{
			for(int j=0;j<num;++j)
			{
				scanf("%d",&s[i][j]);				
				if(s[i][j]!=0)
				{					
					usedr[i][s[i][j]]=true;
					usedc[j][s[i][j]]=true;
					useds[n*(i/n)+(j/n)][s[i][j]]=true;
				}
			}			
		}
		//print();
		backtrack(0);
		if(!ya)
		{
			if(!changeline)
				changeline=true;
			else
				printf("\n");
			printf("NO SOLUTION\n");
		}

	}
	return 0;
}