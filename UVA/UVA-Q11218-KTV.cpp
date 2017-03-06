/******************
Judge   : uva
Problem : 11218 - KTV
Course  : Course15
discribe:   exactly 3 people should sing together each time
There are exactly 9 people, so you decided that each person sings exactly once. In other words, all the people are divided into 3 disjoint groups, so that every person is in exactly one group.
Given a score for every possible combination of 3 people, what is the largest possible score for all the 3 groups?
Input   :  max 1000 case
			3	//n  1~80(the number of possible combinations)
			1 2 3 1	// a, b, c, s (1 <= a < b < c <= 9, 0 < s < 10000), that means a score of s is given to the combination (a,b,c)
			4 5 6 2
			7 8 9 3
			4
			1 2 3 1
			1 4 5 2
			1 6 7 3
			1 8 9 4
			0
Output  :
			Case 1: 6
			Case 2: -1
Solve   :bitwise operator
         9 8 7 6 5 4 3 2 1
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 100
struct combination
{
	int state,s;
}com[MAXN];
int ans,n;
void DP(int st,int sum)
{
	//printf("%d %d\n",st,sum);
	if(st==(1<<9)-1)
	{
		ans=ans<sum?sum:ans;
		return;
	}
	for(int i=0;i<n;++i)
	{
		//printf("!%d %d\n",i,st & com[i].state);
		if((st & com[i].state)==0)
		{
			DP(st|com[i].state,sum+com[i].s);
		}
	}
}

int main()
{
	int in,i,j;
	int T=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		
		for(i=0;i<n;++i)
		{
			com[i].state=0;
			for(j=0;j<3;++j)
			{
				scanf("%d",&in);
				in--;
				com[i].state|=(1<<in);
			}
			scanf("%d",&com[i].s);
		}
		ans=-1;
		DP(0,0);
		printf("Case %d: %d\n",T++,ans);
	}
	return 0;
}