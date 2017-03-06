/******************
Judge   : poj
Problem : 2318-TOYS
Course  : Course18
discribe: determine how many toys fall into each partition as John throws them into the toy box.
Input	:
			5 6 0 10 60 0	//n(#box) m(#toy) (x1,y1) (x2,y2)
			3 1				//(ui,li)
			4 3
			6 8
			10 10
			15 30			//(un,ln)
			1 5				//toy position
			2 1
			2 8
			5 5
			40 10
			7 9
			4 10 0 10 100 0 //n(#box) m(#toy) (x1,y1) (x2,y2)
			20 20
			40 40
			60 60
			80 80
			 5 10
			15 10
			25 10
			35 10
			45 10
			55 10
			65 10
			75 10
			85 10
			95 10
			0				//over

Output	:
			0: 2
			1: 1
			2: 1
			3: 1
			4: 0
			5: 1

			0: 2
			1: 2
			2: 2
			3: 2
			4: 2
( Separate the output of different problems by a single blank line.)
solve:
		geometry
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 5

typedef struct POINT POINT;
struct POINT
{
	double x,y;
}p[MAX];

int cross(int a,int b,int c,int d)
{
	// ab X cd
	return (p[b].x-p[a].x)*(p[d].y-p[c].y)-(p[b].y-p[a].y)*(p[d].x-p[c].x);
}

double point(int xy)
{
	double tri=(double)cross(3,1,1,2)/(double)cross(3,4,1,2);
	if(xy==0)
		return p[3].x+tri*(p[4].x-p[3].x);
	else
		return p[3].y+tri*(p[4].y-p[3].y);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--)
	{
		for(int i=1;i<MAX;++i)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		if(cross(1,2,3,4)==0)
		{
			if(cross(1,2,1,3)==0 && cross(1,2,1,4)==0)
				printf("LINE\n");
			else
				printf("NONE\n");
		}
		else
		{
			printf("POINT");
			printf(" %.2lf %.2lf\n",point(0),point(1));
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}