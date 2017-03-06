/******************
Judge   : POJ
Problem : 1200-Crazy_Search.cpp
Course  : Course2
discribe: find the substring(n word) of input string(with nc character) and count the number of type of substring
Input   : //n nc
		  //string 
		  3 4
		  daababac
Output  : //number of type
		  5
Solve   : hash (map will tle)

*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int charHash[30];
bool hash[17000000];
char s[1000000];
int main()
{
	int n,nc,len;
	int i,j,cnt,sum,ans;
	while(scanf("%d%d",&n,&nc)!=EOF)
	{
		cnt=1;	ans=0;
		memset(charHash,0,sizeof(charHash));
		memset(hash,false,sizeof(hash));
		//getchar();
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<=len-n;++i)
		{
			sum=0;
			for(j=0;j<n;++j)
			{
				if(charHash[s[i+j]-'a']==0)
				{
					charHash[s[i+j]-'a']=cnt;
					cnt++;
				}
				sum*=nc;
				sum+=charHash[s[i+j]-'a'];
			}
			if(!hash[sum])
			{
				hash[sum]=true;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}