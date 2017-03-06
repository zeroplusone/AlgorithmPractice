#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 110
string s1,s2,virus;
int lcs[MAX][MAX];
/*
void KMP(char sub[],string v)
{
	
}
*/
int main()
{
	int ans,now,same;
	while(cin>>s1>>s2>>virus)
	{
		ans=0;
		memset(lcs,0,sizeof(lcs));
		char sub[MAX];
		now=0;	same=-1;

		for(int i=0;i<s1.size();++i)
		{
			for(int j=0;j<s2.size();++j)
			{
				if(s1[i]==s2[j])
				{
					lcs[i+1][j+1]=lcs[i][j]+1;
					sub[now]=s1[i];
					now++;

				}
				else if(s1[i]!=s2[j])
				{
					lcs[i+1][j+1]=max(lcs[i][j+1],lcs[i+1][j]);

					
				}
				if(lcs[i+1][j+1]>ans)
					ans=lcs[i+1][j+1];
			}
		}
		
		//KMP(sub,virus);
		int j;
		if(now>=virus.size())
		{
			for(int i=0;i<=now-virus.size();++i)
			{
				for(j=0;j<virus.size();++j)
				{
					if(sub[i+j]!=virus[j])
						break;
				}
				if(j==virus.size())
					same=i;
			}
			if(same!=-1)
			{
				if(i>=now-virus.size()-i)
				{
					for(int i=0;i<same;++i)
						printf("%c",sub[i]);
					printf("\n");
				}
				else
				{
				
				}
			}
		}
		else
		{
			for(int i=0;i<now;++i)
				printf("%c",sub[i]);
			printf("\n");
		}
	}
}
