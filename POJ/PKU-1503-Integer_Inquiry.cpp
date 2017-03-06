#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	string s[150];
	char in[150];
	int len[150];
	memset(len,0,sizeof(len));
	int i=0,max=0;
	while(scanf("%s",in))          //POJ 不能getline  字串不能相加
	{			
		s[i]=string(in);
		len[i]=s[i].length();
		if(len[i]==1 && s[i][0]=='0')
			break;
		if(len[i]>max)
			max=len[i];
		++i;
	}
	stack<char> ans;
	int add=0;
	int now;
	char c;
	for(int j=1;j<=max;++j)
	{
		now=0;
		for(int k=0;k<i;++k)
		{
			if(len[k]-j>=0)
				now+=s[k][len[k]-j]-'0';
			
		}
		
		now+=add;
		add=now/10;		
		c='0'+now%10;
		ans.push(c);
	}
	while(add!=0)                //剩下的add也要加上
	{
		c='0'+add%10;
		ans.push(c);
		add/=10;
	}
	int flag=1;
	while(!ans.empty())         //最前面0不要印 EX 0024-> 24
	{	
		while(flag && ans.top()=='0')		
			ans.pop();
		flag=0;
		
		printf("%c",ans.top());				
		ans.pop();
	}
	printf("\n");
	return 0;
}