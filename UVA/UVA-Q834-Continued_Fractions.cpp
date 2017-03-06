/*
Sample Input 
43 19         分數43/19=bo+1/(b1+1/(b2+1/....))
1 2

Sample Output  反推出順序
[2;3,1,4]
[0;2]

sol:分母除分子就知道整樹部分為多少
	再將剩下的分樹倒樹繼續做
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int now;

void conti(int a,int b)
{
	switch(now)
	{
		case 0:
			printf("[%d",b==0?a:a/b);	break;
		case 1:
			printf(";%d",b==0?a:a/b);	break;
		default:
			printf(",%d",b==0?a:a/b);	break;
	}
	now++;
	if(a%b==0 || b==0)
		return;
	conti(b,a%b);
}

int main()
{
	int num,deno;
	while(scanf("%d %d",&num,&deno)!=EOF)
	{
		now=0;		
		conti(num,deno);
		printf("]\n");
	}
	return 0;
}
