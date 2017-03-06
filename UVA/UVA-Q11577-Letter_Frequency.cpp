#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
	string s;
	int n;
	scanf("%d",&n);
	int a[26],max;
	getchar();
	for(int i=0;i<n;++i)
	{
		getline(cin,s);
		
		for(int j=0;j<26;++j)
			a[j]=0;
			
		for(int j=0;j<s.length();++j)
		{
			if( s[j]>='A' && s[j]<='Z')
				a[s[j]-'A']++;
			else if(s[j]>='a' && s[j]<='z')
				a[s[j]-'a']++;
		}
		
		max=0;
		queue <char> f;
		for(int j=0;j<26;++j)
		{
			if(a[j]>max)
			{
				while(!f.empty())
				{
					f.pop();			
				}
				max=a[j];
				f.push('a'+j);
			}
			else if(a[j]==max)
			{
				f.push('a'+j);
			}
		}
		
		while(!f.empty())
		{
			printf("%c",f.front());
			f.pop();			
		}
		printf("\n");
		
	}
	return 0;
}