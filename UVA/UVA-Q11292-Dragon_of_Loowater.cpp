/*
Sample Input:
2 3   //鴨子數 士兵樹
5
4    ->鴨子頭直徑
7
8
4   ->士兵身高
2 1  //下一筆資料
5
5
10
0 0     //結束

Output for Sample Input:  //士兵要高於壓的直徑才能殺
11                        //雇用士兵1公分1快 球最小的花費
Loowater is doomed!       //殺不了

sol:greedy 找大於壓頭最小的是冰
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 20010
int d[MAX];
int k[MAX];
int ans;
int main()
{
	int n,m,count;
	while(scanf("%d %d",&n,&m)!=EOF)
	{	
		if(n==0 && m==0)
			break;
		for(int i=0;i<n;++i)
			scanf("%d",&d[i]);
		for(int i=0;i<m;++i)
			scanf("%d",&k[i]);
		if(n>m)
			printf("Loowater is doomed!\n");
		else
		{
			sort(d,d+n);
			sort(k,k+m);		
			count=0;	ans=0;
			for(int i=0,now=0;i<n;++i)
			{
				for(int j=now;j<m;++j)
				{
					if(d[i]>k[j])
						continue;
					else
					{						
						ans+=k[j];
						now=j+1;     //WA
						count++;
						break;
					}
				}
			}	
			if(count==n)
				printf("%d\n",ans);
			else
				printf("Loowater is doomed!\n");
		}
	}
	return 0;
}