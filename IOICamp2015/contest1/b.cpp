#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 110
char in[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		getchar();
		scanf("%s",in);
		printf("%s\n",in);
	}
	return 0;
}
