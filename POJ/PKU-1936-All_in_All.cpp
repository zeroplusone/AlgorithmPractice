#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		int flag=0;
		int now=0;
		for(int i=0;i<s2.length()&&now!=s1.length();++i)
		{
			
			if(s1[now]==s2[i])
				now++;
		}
		if(now==s1.length())
		{	
			flag=1;		
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}