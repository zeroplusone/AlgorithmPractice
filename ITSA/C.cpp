#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 10100
char in[MAX];

int main()
{
	int len;
	bool ok=true;
	while(scanf("%s",in)!=EOF)
	{
		len=strlen(in);
		ok=true;
		for(int i=0;i<len/2;++i)
		{
			if(in[i]!=in[len-i-1])
			{
				ok=false;
				break;
			}
		}
		if(ok)
			printf("%s is a palindrome.\n");
		else
			printf("%s is not a palindrome.\n");
	}
	return 0;
}