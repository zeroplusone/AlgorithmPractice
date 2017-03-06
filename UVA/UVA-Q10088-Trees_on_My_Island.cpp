/******************
Judge   : UVA
Problem : 10088 - Trees on My Island
Course  : 2015-進階20150125
discribe: pick's theorem , calculate I
Input   : 
	 12			// n node
	 3 1 		//position
	 6 3
	 9 2
	 8 4
	 9 6
	 9 9
	 8 9
	 6 5
	 5 8
	 4 4
	 3 5
	 1 3
	 12			/n
	 1000 1000
	 2000 1000
	 4000 2000
	 6000 1000
	 8000 3000
	 8000 8000
	 7000 8000
	 5000 4000
	 4000 5000
	 3000 4000
	 3000 5000
	 1000 3000
	 0		//over

Output  : 
	21
 	25990001

Solve   :pick's theorem


//WA : Area may be nagative. must turn to positive
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MAXN 1100

int n;

typedef struct POINT POINT;
struct POINT
{
	long long int x,y;
}p[MAXN];

double cross(POINT a,POINT b)
{
	return a.x*b.y-b.x*a.y;
}

int GCD(long long int a,long long int b)
{
	long long int tmp;
	a=a<0?a*(-1):a;
	b=b<0?b*(-1):b;

	if(b>a)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	
	while(b!=0)
	{
		tmp=a;
		a=b;
		b=tmp%a;
	}
	return a;
}

double AREA()
{
	double ans=0;
	for(int i=0;i<n;++i)
		ans+=cross(p[i],p[i+1]);
	ans=ans<0?ans*(-1):ans;
	return ans/2.0;
}

long long int EDGE_POINT()
{
	long long int ans=0;
	for(int i=0;i<n;++i)
		ans+=GCD(p[i+1].x-p[i].x,p[i+1].y-p[i].y);
	return ans;
}

int main()
{
	//A=I+E/2-1;  
	long long int E,I;
	double A;

	int i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		for(i=0;i<n;++i)		
			scanf("%lld%lld",&p[i].x,&p[i].y);
		
		p[n].x=p[0].x;	p[n].y=p[0].y;
		A=AREA();
		E=EDGE_POINT();

		I=A+1.0-((double)E/2.0);
		printf("%lld\n",I);
	}
	return 0;
}