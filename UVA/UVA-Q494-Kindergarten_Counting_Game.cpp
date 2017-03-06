#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	string s;
	int count,i;
	while(getline(cin,s))
	{
		count=0;
		
		for(int i=0;i<s.length();++i)
		{
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
			{
				while( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
					i++;
				count++;			
			}
		}
		printf("%d\n",count);
	}
	return 0;
}