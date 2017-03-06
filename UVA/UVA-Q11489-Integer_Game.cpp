/******************
Judge   : UVA
Problem : 11489 - Integer Game
Course  : Course3
discribe:  Two players, S and T,  S plays first. 
		 the number of digits in N is odd then S wins otherwise T wins.
			 A player can remove a particular digit if the sum of digits of the resulting number is a multiple of 3 or there are no digits left.
Input   :
			3	//case
			4	//q(max 1000 digit)
			33
			771

Output	:
			Case 1: S
			Case 2: T
			Case 3: T
solve:
		ad hoc
		->only can take digit that can divide by 3
*******************/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1500
char in[MAXN];
int left[MAXN];

int main()
{
	int c,cc;
	int n,now,i,all;
	bool three=false;
	scanf("%d",&c);
	getchar();
	for(cc=1;cc<=c;++cc)
	{		
		printf("Case %d: ",cc);
		gets(in);
		all=0;	
		now=0;
		n=strlen(in);

			for(i=0;i<n;++i)
			{		
				all+=in[i]-'0';
				if((in[i]-'0')%3==0)	now++;
			}

			if(all%3==0)
			{
				if(now%2==1)
					printf("S\n");
				else
					printf("T\n");
			}
			else
			{
				three=false;
				for(i=0;i<n;++i)
				{
					if((all-(in[i]-'0'))%3==0)
					{	
						three=true;
						break;
					}	
				}
					if(!three)
						printf("T\n");
					else if(now%2==1)
						printf("T\n");
					else
						printf("S\n");
				}
			
		
	}
	return 0;
}