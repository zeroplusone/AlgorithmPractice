#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string s;
	int count;
	while(getline(cin,s))
	{	
		count=0;
		for(int i=0;i<s.length();++i)
		{
			if( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') )
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}