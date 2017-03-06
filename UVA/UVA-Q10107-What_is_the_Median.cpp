/******************
Judge   : UVA
Problem : 10107-What_is_the_Median?
Course  : Course1
discribe: find the median until now
Input   : x0
		  x1
		  x2
		  .
		  .
		  xn-1
Output  : med0
          med1
		  med2
		  .
		  .
		  med n-1
Solve   : insertion sort
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 10010
int x[MAX];

int main()
{
	int i=0;
	int j,k,tmp;
	while(scanf("%d",&x[i])!=EOF)
	{		
		tmp=x[i];
		for(j=i-1;j>=0;--j)
		{
			if(x[j]>tmp)	
				x[j+1]=x[j];
			else
				break;
		}
		x[j+1]=tmp;
		if(i%2==0)	//odd
			printf("%d\n",x[i/2]);
		else		//even
			printf("%d\n",(x[i/2]+x[i/2+1])/2);
		i++;
	}
}