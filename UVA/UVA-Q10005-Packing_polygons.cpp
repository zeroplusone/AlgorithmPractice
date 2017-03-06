/******************
Judge   : UVA
Problem : 10005 - Packing polygons
Course  : 2015-進階20150125
discribe: minimum enclising circle
Input   : 
	3	// n point
	0 0	// x y
	1 0
	0 1
	1.0	// r can include?
	3
	0 0
	1 0
	0 1
	0.1
	0


Output  : 
The polygon can be packed in the circle.	//yes
There is no way of packing that polygon.	//no

Solve   :minimum enclising circle

*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MAXN 150
#define eps 1e-6
int n;

typedef struct POINT POINT;
struct POINT
{
	double x,y;
}p[MAXN],cenPoint,cen;


double eq(double a, double b)
{
    return fabs(a-b)<eps;
}

double dis(POINT a,POINT b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


double THREE_POINTS_FIND_CIRCLE(POINT a,POINT b,POINT c)
{
	// a1*x +b1*y+c1=0		-> AB 
	// a2*x +b2*y+c2=0		-> AC
	double a1,a2,b1,b2,c1,c2;
	POINT cen1,cen2,ans;
	a1=a.x-b.x;	b1=a.y-b.y;
	a2=a.x-c.x;	b2=a.y-c.y;

	cen1.x=(a.x+b.x)/2.0;
	cen1.y=(a.y+b.y)/2.0;
	cen2.x=(a.x+c.x)/2.0;
	cen2.y=(a.y+c.y)/2.0;

	c1=(-1)*(a1*cen1.x+b1*cen1.y);
	c2=(-1)*(a2*cen2.x+b2*cen2.y);

	ans.x=(-1)*(b2*c1-b1*c2)/(b2*a1-b1*a2);
	ans.y=(-1)*(a2*c1-a1*c2)/(a2*b1-a1*b2);

	return dis(a,ans);
}

/*
struct LINE
{
    double a,b,c;
}L1,L2;
void getl(POINT p1, POINT p2, LINE &l)//ax=by=c=0;
{
    l.a=p2.x-p1.x;
    l.b=p2.y-p1.y;
    l.c=0.0-(l.a*(p1.x+p2.x)/2.0+l.b*(p1.y+p2.y)/2.0);
}
void getp(LINE l1, LINE l2, POINT &pot)
{
    double bse;
    bse=l1.a*l2.b-l1.b*l2.a;
    pot.x=(l2.c*l1.b-l2.b*l1.c)/bse;
    pot.y=(l1.c*l2.a-l1.a*l2.c)/bse;
}
double THREE_POINTS_FIND_CIRCLE(POINT P1, POINT P2, POINT P3)
{
    getl(P1,P2,L1);
    getl(P2,P3,L2);
    getp(L1,L2,cenPoint);
    return dis(cenPoint,P1);
}
*/
double MIN_CIRCLE_WITH_TWO_POINTS(POINT P1,POINT P2,int m)
{
	cen.x=(P1.x+P2.x)/2.0;
	cen.y=(P1.y+P2.y)/2.0;
	double r=dis(P1,P2)/2.0;
	int i;
	for(i=0;i<m;++i)				//find another circle
	{
		if(dis(cen,p[i])>r)			//the third point is still not in the circle
			r=THREE_POINTS_FIND_CIRCLE(P1,P2,p[i]);
	}
	return r;
}

double MIN_CIRCLE_WITH_POINT(POINT P,int m)
{
	cen.x=(p[0].x+P.x)/2.0;
	cen.y=(p[0].y+P.y)/2.0;
	double r=dis(p[0],P)/2.0;
	int i;
	for(i=1;i<m;++i)				//find another circle
	{
		if(dis(cen,p[i])>r)			//the third point is still not in the circle
			r=MIN_CIRCLE_WITH_TWO_POINTS(P,p[i],i);
	}
	return r;
}

double MIN_CIRCLE()
{
	cen.x=(p[0].x+p[1].x)/2.0;
	cen.y=(p[0].y+p[1].y)/2.0;
	double r=dis(p[0],p[1])/2.0;
	int i;
	for(i=2;i<n;++i)
	{
		if(dis(cen,p[i])>r)		//the third point is not in the circle
			r=MIN_CIRCLE_WITH_POINT(p[i],i);
	}
	return r;
}

int main()
{
	int i;
	double r,ans;

	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		for(i=0;i<n;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		
		scanf("%lf",&r);
		//************* ok ***************//
		if(n==1)		ans=0;
		else if(n==2)	ans=dis(p[0],p[1]);
		else			ans=MIN_CIRCLE();
		if(r>=ans)	printf("The polygon can be packed in the circle.\n");
		else		printf("There is no way of packing that polygon.\n");
		
		/*if(n==1 & r>0-eps)
            printf("The polygon can be packed in the circle.\n");
        else if(eq(r,0.0))
            printf("There is no way of packing that polygon.\n");
        else if(MIN_CIRCLE()-eps<r)
            printf("The polygon can be packed in the circle.\n");
        else
            printf("There is no way of packing that polygon.\n");
            */
	}
	return 0;
}