#include <cstdio>
#include <iostream>
#include <cstring>
#include<string>
#include <algorithm>
using namespace std;

int main()
{
	int t,a,b;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
			printf(">\n");
		else if(a<b)
			printf("<\n");
		else
			printf("=\n");
	}
	return 0;
}