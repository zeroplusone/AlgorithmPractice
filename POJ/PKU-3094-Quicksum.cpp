#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	char in[300];          //POJ¤£¯àgetline
	string s;
	long long int ans;
	while(gets(in))
	{
		ans=0;
		s=string(in);
		//cout<<s<<endl;
		if(s.length()==1 && s[0]=='#')
			break;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='A' && s[i]<='Z')
				ans+=(i+1)*(s[i]-'A'+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}