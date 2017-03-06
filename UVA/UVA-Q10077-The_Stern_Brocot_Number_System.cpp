/******************
Judge   : UVA
Problem : 10077 - The Stern-Brocot Number System
Course  : Course3
discribe: Insert (m'+n')/n+n' between two adjacent fractions m/n and m'/n'.

Input	:
			5 7			//son mother
			878 323
			1 1			//end

Output	:
			LRRL
			RRLRRLRLLLLRLRRR

solve:
		ad hoc
*******************/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int i,j,addil,addjl,addir,addjr;

	while(scanf("%d %d",&m,&n)!=EOF)
	{
		if(n==1 && m==1)	break;
		i=1;	j=1;
		addir=1;	addjr=0;
		addil=0;	addjl=1;
		
			while(!(i==m && j==n))
			{
				if(m*j<n*i)	//m/n < i/j
				{
					printf("L");
					addir=i;	addjr=j;	
					i=addil+i;
					j=addjl+j;
								
				}
				else
				{
					printf("R");
					addil=i;	addjl=j;	
					i=addir+i;
					j=addjr+j;
				}
			}
		printf("\n");
		
	}
	return 0;
}