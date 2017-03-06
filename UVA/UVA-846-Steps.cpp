/******************
Judge   : UVA
Problem : 846 - Steps
Course  : Course3
discribe: . The length of a step must be nonnegative and can be by one bigger than, equal to, or by one smaller than the length of the previous step.
			minimum number of steps

Input	:
			3		//case
			45 48	//from to
			45 49
			45 50

Output	:
			3		//step
			3
			4

solve:
		ad hoc
*******************/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int c;
	int a,b,ans;
	int i;
	scanf("%d",&c);
	while(c--)
	{
		ans=0;
		scanf("%d%d",&a,&b);
		a=b-a;
		if(a==0)
		ans=0;
		else
		{
			b=0;
			for(i=1;;i++)
			{
				b+=2*i;
				if(a-b<0)
				{
					if(b-a<i)
						ans+=2;
					else
						ans+=1;
					break;	
				}
				else
				{				
					ans+=2;
					if(a-b==0)	break;
				}	
			}
		}	
		printf("%d\n",ans);
	}
	return 0;
}