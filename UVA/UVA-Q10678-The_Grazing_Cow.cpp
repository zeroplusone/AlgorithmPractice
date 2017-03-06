/******************
Judge   : UVA
Problem : 10678 - The Grazing Cow
Course  : Course3
discribe: A rope in the field is tied with two pillars. The cow is kept tied with the rope with the help of a ring.
Input   :
			3
			10 12
			23 45
			12 18

Output	:
			62.517
			1366.999
			189.670
solve:
		ad hoc(¾ò¶ê A=a*b*pi)
*******************/
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
const double PI=2*acos(0);
int main()
{
	int n;
	int d,l;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&d,&l);
		printf("%.3lf\n",(l/(double)2)*PI*sqrt(((double)l*l/(double)4)-((double)d*d/(double)4)));
	}
	return 0;
}