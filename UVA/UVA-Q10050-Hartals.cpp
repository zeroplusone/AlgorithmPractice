/******************
Judge   : UVA
Problem : UVA-Q10050-Hartals
Course  : Course3
discribe: . h (called the hartal parameter) that denotes the average number of days between two successive hartals (strikes) called by the corresponding party.
             One must always start the simulation on a Sunday and assume that there will be no hartals on weekly holidays (on Fridays and Saturdays).
Input	:
            2   //(case)
            14  //N(day) 7~3650
            3   //p(party) 1~100
            3
            4
            8
            100 //N
            4
            12
            15
            25
            40

Output	:
            5	//have time
            15

solve:
		ad hoc
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 150
int h[MAXN];

int main()
{
	int c;
	int n,p;
	int i,j;
	int ans;
	bool ya=false;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d%d",&n,&p);
		for(i=1;i<=p;++i)
			scanf("%d",&h[i]);
		ans=0;
		for(i=1;i<=n;++i)
		{
			if(i%7==0 || i%7==6)
				continue;
			ya=false;
			for(j=1;j<=p;++j)
			{
				if(i%h[j]==0)
				{
					ya=true;
					break;
				}
			}
			if(ya)	ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
