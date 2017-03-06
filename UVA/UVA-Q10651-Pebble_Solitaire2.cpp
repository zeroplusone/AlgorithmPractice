/******************
Judge   : uva
Problem : 10651 - Pebble Solitaire
Course  : Course15
discribe: A is vacant, but B and C each contain a pebble. The move constitutes of moving the pebble from C to A, and removing the pebble in B from the board.
		The aim of the game is to remove as many pebbles as possible from the board.
Input   :
		
		5
		---oo-------
		-o--o-oo----
		-o----ooo---
		oooooooooooo
		oooooooooo-o

Output	:
		1
		2
		3
		12
		1
solve:
		bitwise
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXN 12
int dp[1<<MAXN];

int DP(int s,int rest)
{
	int i=0,ans=99;
	bool flag=false;
	for(i=0;i<MAXN;++i)
	{
		if(s&(1<<i))
		{
			if(i>1 && (s&(1<<(i-1))) && !(s&(1<<(i-2))))	//right
			{	
				ans=min(ans,DP(s&(~(1<<i))&(~(1<<(i-1)))|(1<<(i-2)),rest-1));
				flag=true;
			}
			if(i<10 && (s&(1<<(i+1))) && !(s&(1<<(i+2))))	//left
			{
				ans=min(ans,DP(s&(~(1<<i))&(~(1<<(i+1)))|(1<<(i+2)),rest-1));
				flag=true;
			}
		}
	}
	if(!flag)
	{
		ans=0;
		for(i=0;i<MAXN;++i)
		{
			if(s&(1<<i))
				ans++;
		}
	}
	return ans;
}

int main()
{
	int n,i,s,chess;
	string in;
	while(scanf("%d",&n)!=EOF)
	{		
		while(n--)
		{
			cin>>in;
			s=0;	chess=0;
			for(i=0;i<in.length();++i)
			{
				if(in[i]=='o')
				{
					s|=(1<<i);	//upside down
					chess++;
				}
			}
			printf("%d\n",DP(s,chess));
		}
	}
	return 0;
}