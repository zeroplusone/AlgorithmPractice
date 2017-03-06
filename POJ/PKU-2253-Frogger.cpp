/******************
Judge   : POJ
Problem : 2253-Frogger2253-Frogger
Course  : Course10
discribe: compute the frog distance between Freddy's and Fiona's stone. 
Input	:
			2	//#node(2-200)
			0 0	//stone i's x y //start
			3 4					//end

			3
			17 4				//start
			19 4				//end
			18 5

			0

Output	:
			Scenario #1
			Frog Distance = 5.000

			Scenario #2
			Frog Distance = 1.414
			
			(three decimals. Put a blank line after each test case)

solve:
		coordinate->dijkstra
[direction ,no cycle]
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 250
int r[MAXN][MAXN];
bool v[MAXN];

int main()
{
	int n;
	int i;
	int casenum=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		for(i=1;i<=n;++i)
		
		printf("Scenario #%d\n",casenum++);
		printf("Frog Distance = %.3f\n",);
	}
	return 0;
}