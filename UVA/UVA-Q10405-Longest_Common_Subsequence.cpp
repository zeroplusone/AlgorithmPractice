#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

#define MAX 1010
string s1,s2;
int lcs[MAX][MAX];

int main()
{
	int ans;
	while(getline(cin,s1))
	{
		
		getline(cin,s2);
		ans=0;
		for(int i=0;i<MAX;++i)
			for(int j=0;j<MAX;++j)
				lcs[i][j]=0;
		for(int i=0;i<s1.size();++i)
		{
			for(int j=0;j<s2.size();++j)
			{
				if(s1[i]==s2[j])
					lcs[i+1][j+1]=lcs[i][j]+1;
				else if(s1[i]!=s2[j])
				{
					lcs[i+1][j+1]=lcs[i][j+1]>lcs[i+1][j]?lcs[i][j+1]:lcs[i+1][j];
				}
				if(lcs[i+1][j+1]>ans)
					ans=lcs[i+1][j+1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
