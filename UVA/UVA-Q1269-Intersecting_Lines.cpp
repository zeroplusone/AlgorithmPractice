/******************
Judge   : poj
Problem : 1269-Intersecting Lines
Course  : Course18
discribe: 1) no intersection because they are parallel, 2) intersect in a line because they are on top of one another (i.e. they are the same line), 3)intersect in a point.
Input	:
			5
			0 0 4 4 0 4 4 0
			5 0 7 6 1 0 2 3
			5 0 7 6 3 -6 4 -3
			2 0 2 27 1 5 18 5
			0 3 4 0 1 2 2 5

Output	:
			INTERSECTING LINES OUTPUT
			POINT 2.00 2.00
			NONE
			LINE
			POINT 2.00 5.00
			POINT 1.07 2.20
			END OF OUTPUT

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