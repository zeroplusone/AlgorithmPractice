/*
Sample input
6         //幾乘幾
100100    //1代表war eagle 0代表障礙物
001010 
000000
110000
111000
010100
8
01100101
01000001 
00011000 
00000010
11000011
10100010
10000001
01100000

Sample output     //1的九宮格有1代表同一個war eagle
Image number 1 contains 3 war eagles. 
Image number 2 contains 6 war eagles.

sol:用dfs來向外搜尋
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

#define MAX 30
int map[MAX][MAX];
bool visit[MAX][MAX];
int step[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
int n;

void dfs(int x,int y)
{
	if(visit[x][y]==true || map[x][y]==0)
		return;
	//printf("@%d %d\n",x,y);
	visit[x][y]=true;
	for(int i=0;i<8;++i)
	{
		if(x+step[i][0]>=0 &&x+step[i][0]<n && y+step[i][1]>=0 && y+step[i][1]<n)
			dfs(x+step[i][0],y+step[i][1]);
	}
}

int main()
{
	int count=0,ans;
	while(scanf("%d",&n)!=EOF)
	{
		//initial
		ans=0;		count++;
		memset(visit,false,sizeof(visit));
		//read
		getchar();
		string s;
		for(int i=0;i<n;++i)
		{	
			getline(cin,s);
			for(int j=0;j<n;++j)
			{	
				
				map[i][j]=s[j]-'0';
				//printf("%d ",map[i][j]);
			}
			
			//printf("\n");
		}
		for(int i=0;i<n;++i)
		{	for(int j=0;j<n;++j)
			{	
				if(visit[i][j]==false && map[i][j]==1)
				{	
					dfs(i,j);
					ans++;
				}
			}
		}		
		printf("Image number %d contains %d war eagles.\n",count,ans);
	}
	return 0;	
}