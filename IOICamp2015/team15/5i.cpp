#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
const double pi2=8.0*atan(1.0);
const double INF=1e9;
const double eps=1e-6;

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
	node unit() const
	{
		return *this/len();
	}
	node T() const
	{
		return node(-y,x);
	}
	node rot(double rad) const
	{
		return node(cos(rad)*x-sin(rad)*y, sin(rad)*x+cos(rad)*y);
	}

};

double ori(const node& p1,const node& p2,const node& p3)
{
	return (p2-p1)^(p3-p1);
}

pair<node,node> two_circle_intersect(node p1, double r1, node p2, double r2)
{
	double degree=acos(((p2-p1).len2()+r1*r1-r2*r2)/(2*r1*(p2-p1).len()));
	return make_pair(p1+(p2-p1).unit().rot(degree)*r1, p1+(p2-p1).unit().rot(-degree)*r1);
}


node fff(node p1,node p2,node p3)
{
	if((p2-p1)*(p3-p1)/(p3-p1).len()/(p2-p1).len()<=((double)(-1)/2)){
		return p1;
	}
	if((p1-p2)*(p3-p2)/(p1-p2).len()/(p3-p2).len()<=((double)(-1)/2)){
		return p2;
	}
	if((p2-p3)*(p1-p3)/(p2-p3).len()/(p1-p3).len()<=((double)(-1)/2)){
		return p3;
	}
	node cirp1,cirp2;
	double cirr1,cirr2;
	cirr1=(p2-p1).len()/(sqrt(3)/2)/2;
	cirr2=(p3-p1).len()/(sqrt(3)/2)/2;
	cirp1=p1+(((p2-p1).unit()*cirr1).rot((ori(p1,p2,p3)>0?-1:1)*pi/6));
	cirp2=p1+(((p3-p1).unit()*cirr2).rot((ori(p1,p3,p2)>0?-1:1)*pi/6));
	pair<node,node> tmp=two_circle_intersect(cirp1,cirr1,cirp2,cirr2);
	double len1,len2;
	len1=(p1-tmp.first).len()+(p2-tmp.first).len()+(p3-tmp.first).len();
	len2=(p1-tmp.second).len()+(p2-tmp.second).len()+(p3-tmp.second).len();
	if(len1>len2){
		return tmp.second;
	}else{
		return tmp.first;
	}
}


node s[4];


double count(node at,int u)
{
	node fab=fff(s[0],s[u],at);
	double r=0.0;
	r+=(fab-s[0]).len();
	r+=(fab-s[u]).len();
	r+=(fab-at).len();
	for(int i=1;i<=3;i++)
		if(i!=u)
			r+=(s[i]-at).len();
	return r;
}

int inx[4],iny[4];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		/*for(int i=0;i<4;i++)
			scanf("%lf%lf",&s[i].x,&s[i].y);*/
		for(int i=0;i<4;i++)
			scanf("%d%d",inx+i,iny+i);
		double ans_all=INF,ans;
		int size=4;
		for(int i=3;i>=0;i--)
			for(int j=i-1;j>=0;j--)
				if(inx[i]==inx[j] && iny[i]==iny[j])
				{
					for(int k=i+1;k<size;k++)
					{
						//s[k-1]=s[k];
						inx[k-1]=inx[k];
						iny[k-1]=iny[k];
					}
					size--;
					break;
				}
		for(int i=0;i<4;i++)
			s[i]=node((double)inx[i] , (double)iny[i] );
		if(size==1)
		{
			puts("0.000000");
		}
		else if(size==2)
		{
			printf("%f\n",(s[0]-s[1]).len()*2);
		}
		else if(size==3)
		{
			node f=fff(s[0],s[1],s[2]);
			double ans=0.0;
			for(int i=0;i<=2;i++)
				ans+=(f-s[i]).len();
			printf("%f\n",ans*2);
		}
		else{
			node now=(s[0]+s[1]+s[2]+s[3])/4;
			ans=count(now,1);
			ans=min(ans,count(now,2));
			ans=min(ans,count(now,3));
//printf("%f\n",ans);
			double len=1e4;/**/
			double ss=0.999;
			while(len>eps)
			{
				double rt=(double)rand()/RAND_MAX*pi2;
				node go=node(cos(rt),sin(rt))*len;
				double tmp=count(now+go,1);
				for(int i=2;i<4;i++)
					tmp=min(tmp,count(now+go,i));
//printf("%f , %f\n",(now+go).x,(now+go).y);
				while(tmp<ans)
				{
//printf("%f\n",ans);
					ans=tmp;
					now=now+go;
					for(int i=2;i<4;i++)
						tmp=min(tmp,count(now+go,i));
//printf("%f , %f\n",now.x,now.y);
				}
				len*=ss;
			}
			ans_all=min(ans_all,ans);
			printf("%f\n",ans*2);
		}
	}
	return 0;
}
