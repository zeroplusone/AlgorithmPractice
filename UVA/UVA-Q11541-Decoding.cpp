#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int ten(int now,int all)
{
	int ans=1;
	for(int i=0;i<all-now-1;++i)
		ans*=10;
	return ans;
}

int main()
{
	int n;
	scanf("%d",&n);
	string s;
	int num;
	char mem;
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		printf("Case %d: ",i);
		for(int j=0;j<s.length();)
		{
			mem=s[j];
			++j;
			string ss;
			while(!(s[j]>='A' && s[j]<='Z') && j!=s.length())
			{
				ss=ss+s[j];
				++j;
			}  
			num=0; 
			for(int l=0;l<ss.length();++l)
			{
				num+=(ss[l]-'0')*ten(l,ss.length());     
			}        
			for(int k=0;k<num;++k)
				printf("%c",mem);
		}
		printf("\n");
	}
	return 0;
	
}
