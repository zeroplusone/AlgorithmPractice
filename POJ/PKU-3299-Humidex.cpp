#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;

double t,d,h;
bool ft,fd,fh;

void read(char c)
{
	switch(c)
	{
		case 'T': scanf("%lf",&t); ft=true;
			break;
		case 'D': scanf("%lf",&d); fd=true;
			break;
		case 'H': scanf("%lf",&h); fh=true;
			break;
		default:
			break;
	}
}

int main()
{
	char c;
	while(c=getchar())
	{
		t=h=d=0;
		ft=fh=fd=false;
		
		if(c=='E')
			break;
		else
		{
			read(c);			
			getchar(); c=getchar();
			read(c);		
		}
		getchar();          //3種輸入種類
		if(ft&&fd)
			h=t+0.5555*((6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16)))))-10);
		else if(ft&&fh)
			d=-273.16+1/((1/273.16)-log(((h-t)/0.5555+10)/6.11)/5417.7530);
		else if(fd&&fh)
			t=h-(0.5555*((6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16)))))-10));
		printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
	}
	return 0;
}