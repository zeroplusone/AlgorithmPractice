#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	while(getline(cin,s))
	{
		for(int i=0;i<s.length();++i)
			printf("%c",s[i]-7);
		printf("\n");
	}
	return 0;
}