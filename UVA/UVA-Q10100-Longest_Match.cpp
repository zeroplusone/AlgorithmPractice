#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

#define MAX 1010
string s1[MAX],s2[MAX];
int lcs[MAX][MAX];

int save(string s,int wh)
{
	int count=0;
	int l=s.length();
	
	for(int i=0;i<l;++i)
	{
		string tmp;
		while(((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9') || (s[i]>='A'&&s[i]<='Z')) && i<l )
		{			
			tmp=tmp+s[i];
			i++;
		}
		if(tmp!="")
		{
			if(wh==1)
				s1[count]=tmp;
			else
				s2[count]=tmp;
			count++;		
		}
	}
	return count;
}

int main()
{
	int ans,len1,len2;
	int c=1;
	string sa,sb;
	while(getline(cin,sa))
	{
		getline(cin,sb);
		if(sa=="" || sb=="")
		{
			printf("%2d. Blank!\n",c);
			c++;
			continue;
		}
		len1=save(sa,1);		
		len2=save(sb,2);
		ans=0;
		memset(lcs,0,sizeof(lcs));
		for(int i=0;i<len1;++i)
		{
			for(int j=0;j<len2;++j)
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
		printf("%2d. Length of longest match: %d\n",c,ans);
		c++;
		
	}
}
