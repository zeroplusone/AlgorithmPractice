#include <stdio.h>
#include <math.h>

const double pi=3.1415926;

struct node
{
	double x,y;
	node() {}
	node(double a,double b) : x(a),y(b) {}
	~node() {}
	node operator+(const node& rhs) const
	{
		return node(x+rhs.x,y+rhs.y);
	}
	node operator-(const node& rhs) const
	{
		return node(x-rhs.x,y-rhs.y);
	}
	node operator*(double n) const
	{
		return node(x*n,y*n);
	}
	node operator/(double n) const
	{
		return node(x/n,y/n);
	}
	double operator*(const node& rhs) const
	{
		return x*rhs.x+y*rhs.y;
	}
	double operator^(const node& rhs) const
	{
		return x*rhs.y-y*rhs.x;
	}
	double len() const
	{
		return sqrt(x*x+y*y);
	}
	double len2() const
	{
		return x*x+y*y;
	}
};



double aco(node a, node b)
{
	return a*b/a.len()/b.len();
}

node po[100005];

int main()
{
	int cas;
	int n,k;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d",&n,&k);
		for(int i=0; i<k; i++){
			scanf("%lf %lf",&po[i].x,&po[i].y);
		}
		if(k==1){
			printf("-1\n");
			continue;
		}
		if(k==2 && n>3){
			printf("-1\n");
			continue;
		}
		if(k==2 && n==3){
			printf("%f\n",(po[0]-po[1]).len2()*sqrt(3)/4);
			continue;
		}
		double tmp;
		node a=po[0],b=po[1],c=po[2];
		node ab=b-a,ac=c-a,bc=c-b;
		tmp=fabs(ab^ac)/ab.len()/ac.len();
		tmp=bc.len()/tmp/2;
		printf("%f\n",tmp*tmp*sin((double)2*pi/n)*n/2);
	}
	return 0;
}
