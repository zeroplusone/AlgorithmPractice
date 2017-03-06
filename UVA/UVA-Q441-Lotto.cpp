/******************
Judge   : UVA
Problem : 441-Lotto.cpp
Course  : Course7
discribe:  choose 6 number from n number. show every possiblity  
		   C n get 6
Input   : 	n s1 s2 s3 . . sn
			n s1 s2 s3 . . sn
			.
			.
			0
Output  : 	all possibility

			all possibility
Solve   :	backtracking
*******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int s[13];
bool use[13];
int ans[6];
int six;
int k;

void backtrack(int n,int now)
{	
	if(n==6)
	{
		printf("%d",ans[0]);
		for(int i=1;i<6;++i)
			printf(" %d",ans[i]);
		printf("\n");		
		return;
	}
	else
	{
		for(int j=now;j<k;++j)
		{
			if(!use[j])
			{
				use[j]=true;
				ans[n]=s[j];				
				backtrack(n+1,j+1);
				use[j]=false;
			}
		}
	}
}

int main()
{	
	int flag=0;
	while(scanf("%d",&k)!=EOF)
	{		
		if(k==0)			
			break;
		
		for(int i=0;i<k;++i)
			scanf("%d",&s[i]);
		if(flag)	
			printf("\n");				
		else
			flag=1;	
		memset(use,false,sizeof(use));
		six=0;
		backtrack(0,0);
		
	}
	return 0;
}