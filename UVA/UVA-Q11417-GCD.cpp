/******************
Judge   : UVA
Problem : 11417 - GCD
Course  : Course3
discribe:  g=sigma(i=1~n)sigma(j=i~=n) GCD(i,j)
Input   :
			10	//n
			100
			500
			0	//end

Output	:
			67
			13015
			442011
solve:
		ad hoc
*******************/
#include<bits/stdc++.h>
using namespace std;

int gcdd(int a,int b)
{
	/*int tmp;
	while(b%a!=0)
	{
		if(a==1)	break;
		tmp=a;
		a=b%a;
		b=tmp;
	}*/
	int tmp;
	while(b>0 && a>0)
	{
		if(a>b)
		{
			a%=b;
			tmp=b;
		}
		else
		{
			b%=a;
			tmp=a;
		}
	}
	return tmp;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		int g=0;
		int i,j;
		for(i=1;i<n;++i)
		{
			for(j=i+1;j<=n;++j)
			{
				g+=gcdd(i,j);
			}
		}
		printf("%d\n",g);
	}
	return 0;
}