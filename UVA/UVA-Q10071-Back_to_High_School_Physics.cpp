#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	unsigned int v,t;
	while(scanf("%d %d",&v,&t)!=EOF)
	{
		printf("%d\n",v*t*2);		
	}
	return 0;
}