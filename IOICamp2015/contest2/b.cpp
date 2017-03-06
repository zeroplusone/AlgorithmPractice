#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	bool ans;
	stack<char> r;
	string s;
	int len,i;
	while(T--)
	{
		while(!r.empty())	r.pop();
		ans=true;
		cin>>s;
		len=s.length();
		for(i=0;i<len;++i)
		{
			if(!r.empty())
			{
				if(r.top()==s[i])
					r.pop();
				else
					r.push(s[i]);
			}
			else
				r.push(s[i]);
		}
		if(r.empty())	printf("Yes\n");
		else		printf("No\n");
	}
	return 0;
}
