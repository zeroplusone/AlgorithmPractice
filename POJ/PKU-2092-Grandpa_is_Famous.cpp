/*
Sample Input
4 5           有4*5個數字     
20 33 25 32 99
32 86 99 25 10
20 99 10 33 86
19 33 74 99 32
3 6
2 34 67 36 79 93
100 38 21 76 91 85
32 23 85 31 88 1
0 0

Sample Output     印出出現次數第二多的數字
32 33
1 2 21 23 31 32 34 36 38 67 76 79 88 91 93 100
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

int main()
{
	int n,m,in,max,save;
	map<int,int> rank;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
			break;
		rank.clear();
		max=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{	
				scanf("%d",&in);
				rank[in]++;
				if(rank[in]>max)
				{	
					max=rank[in];
					save=in;
				}
			}
		}
		rank.erase(rank.find(save));
		max=0;
		 
		for (std::map<int,int>::iterator itr=rank.begin(); itr!=rank.end(); ++itr)
			if(itr->second>max)	max=itr->second;
		for (std::map<int,int>::iterator itr=rank.begin(); itr!=rank.end(); ++itr)			
			if(itr->second==max)	
				printf("%d ",itr->first);		
		printf("\n");
	}
	return 0;
}
