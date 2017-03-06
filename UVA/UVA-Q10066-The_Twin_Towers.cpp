/*
Sample Input
7 6   //n1 n2 
20 15 10 15 25 20 15   //N1
15 25 10 20 15 20      //N2
8 9
10 20 20 10 20 10 20 10
20 10 20 10 10 20 10 10 20
0 0
 
Sample Output
Twin Towers #1
Number of Tiles : 4

Twin Towers #2
Number of Tiles : 6

SOL : LCS
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 150
int lcs[MAX][MAX];
int t1[MAX];
int t2[MAX];

int main()
{
	int ans,n1,n2,c;
	c=1;
	while(scanf("%d %d",&n1,&n2))
	{
		if(n1==0 && n2==0)
			break;
		ans=0; 
		memset(lcs,0,sizeof(lcs));
		for(int i=0;i<n1;++i)
			scanf("%d",&t1[i]);
		for(int i=0;i<n2;++i)
			scanf("%d",&t2[i]);
			
		for(int i=0;i<n1;++i)
		{
			for(int j=0;j<n2;++j)
			{
				if(t1[i]==t2[j])
					lcs[i+1][j+1]=lcs[i][j]+1;
				else if(t1[i]!=t2[j])
				{
					lcs[i+1][j+1]=lcs[i][j+1]>lcs[i+1][j]?lcs[i][j+1]:lcs[i+1][j];
				}
				if(lcs[i+1][j+1]>ans)
					ans=lcs[i+1][j+1];
			}
		}
		
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",c,ans);
		c++;
	}
}
