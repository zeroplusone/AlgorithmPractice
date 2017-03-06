#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 1010
string s1,s2;
int lcs[MAX][MAX];
/*
void print()
{
	for(int i=0;i<=s1.size();++i)
	{
		for(int j=0;j<s2.size();++j)
			printf("%d ",lcs[i][j]);
		printf("\n");
	}	
}
*/
int main()
{
	int ans;
	while(cin>>s1>>s2)
	{
		ans=0;
		memset(lcs,0,sizeof(lcs));
		for(int i=0;i<s1.size();++i)
		{
			for(int j=0;j<s2.size();++j)
			{
				if(s1[i]==s2[j])
					lcs[i+1][j+1]=lcs[i][j]+1;
				else if(s1[i]!=s2[j])
				{
					lcs[i+1][j+1]=max(lcs[i][j+1],lcs[i+1][j]);
				}
				if(lcs[i+1][j+1]>ans)
					ans=lcs[i+1][j+1];
			}
		}
		printf("%d\n",ans);
	}
}
