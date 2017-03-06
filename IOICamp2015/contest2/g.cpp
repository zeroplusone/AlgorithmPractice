#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int extgcd(int a,int b.int &x,int &y)
{
	int d=a;
	if(b!=0)
	{
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else	x=1,y=0;
	return d;
}

int main()
{
	int T,a,b;	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",extgcd(a,b,x,y));
	}
	return 0;
}
