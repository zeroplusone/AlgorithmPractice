/******************
Judge   : POJ
Problem : 1068-Parencodings
Course  : Course2
discribe: give the number that how many left parantheses before right parantheses
          calculate that how many parantheses are in the parantheses of this right arantheses
Input   : t(case)
		  n
		  d0 d1 .. dn
		  n
		  d0 d1 .. dn
		  .
		  .
		  *t
Output  : answer 
Solve   : stack(push left and then chesk right to pop)

*******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAX 25
int main()
{
	int t,n,d[MAX],last,now,count,tmp;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		scanf("%d",&n);
		for(int k=0;k<n;++k)
			d[k]=0;
		last=0;	
				
		for(int j=0;j<n;++j)
		{
			scanf("%d",&now);
			d[j]=now-last;
			last=now;
			if(d[j]==0)
			{
				tmp=j;
				count=0;
				while(d[tmp]==0)
				{
					count++;
					tmp--;
				}		
				count++;
				d[tmp]--;
				printf("%d ",count);
				
			}				
			else			
			{	
				printf("1 ");
				d[j]--;
			}
		}
		printf("\n");
	}
	return 0;
}
