#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 27
string s1,s2;
int t1[MAX];
int t2[MAX];

int main()
{
	int t;	char c;
	while(getline(cin,s1))
	{		
		getline(cin,s2);
		for(int i=0;i<27;++i)
		{
			t1[i]=0;	t2[i]=0;
		}
		for(int i=0;i<s1.size();++i)
		{
			if(s1[i]>='a' && s1[i]<='z')
			t1[s1[i]-'a']++;
		}
		for(int i=0;i<s2.size();++i)
		{
			if(s2[i]>='a' && s2[i]<='z')
			t2[s2[i]-'a']++;
		}
		for(int i=0;i<26;++i)
		{
			t=t1[i]<t2[i]?t1[i]:t2[i];
			if(t!=0)
			{
				c='a'+i;
				for(int j=0;j<t;++j)
					printf("%c",c);
			}
		}
		printf("\n");
	}
	return 0;
}
