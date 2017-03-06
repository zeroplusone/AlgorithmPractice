// Hacker Cup 2017
// Round 2
// Rain over New York
// Jacob Plachta

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=getchar();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

#define MOD 1000000007
#define LIM 800002

PR GCD(int a,int b)
{
		if (!b)
			return(mp(1,0));
	PR p=GCD(b,a%b);
	return(mp(p.y,p.x-p.y*(a/b)));
}

int Add(int a,int b)
{
	a+=b;
		if (a>=MOD)
			a-=MOD;
	return(a);
}

int Sub(int a,int b)
{
	a-=b;
		if (a<0)
			a+=MOD;
	return(a);
}

int Mult(int a,int b)
{
	return((LL)a*b%MOD);
}

int Div(int a,int b)
{
	b=GCD(b,MOD).x;
		if (b<0)
			b+=MOD;
	return(Mult(a,b));
}

int main()
{
	// vars
	int T,t;
	int N,M,K,L,A,B;
	int i,j,a,a2,b,b2,h,h2,h3,h4,w2,w3,sum,cnt;
	int ansB,ansW,ansG,ansR;
	set<int> S;
	set<int>::iterator I;
	static int H[LIM],D[LIM];
	static PR P[LIM];
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input
			Read(N),Read(M),Read(K);
			M=sum=0;
				while (K--)
				{
					Read(L),Read(h),Read(A),Read(B);
						while (L--)
						{
							P[M]=mp(h,M);
							H[M++]=h;
							sum=Add(sum,h);
							h=((LL)A*h+B)%(N-1)+1;
						}
				}
			// init
			ansW=ansR=cnt=0;
			S.clear();
			S.insert(-1);
			S.insert(M);
			Fill(D,0);
			// iterate down through heights
			sort(P,P+M);
				FoxR(i,M)
				{
					// get active interval
					j=P[i].y;
					I=S.lower_bound(j);
					b=*I-j-1;
					I--;
					a=j-*I-1;
					S.insert(j);
					// clouds
					h=N-P[i].x;
					h2=Div(Mult(h,h+1),2);
					w2=Mult(a+1,b+1);
					cnt=Add(cnt,Mult(h2,w2));
					h3=Div(Mult(h,Mult(h+1,h+2)),6);
					a2=Div(Mult(a,a+1),2);
					b2=Div(Mult(b,b+1),2);
					w3=Add(w2,Add(Mult(a2,b+1),Mult(b2,a+1)));
					ansW=Add(ansW,Mult(h3,w3));
					// rain
					ansR=Add(ansR,Mult(P[i].x,Mult(h2,w3)));
					h4=Div(Mult(h-1,Mult(h,h+1)),6);
					ansR=Add(ansR,Mult(h4,w3));
					// rain to retract
					D[j-a]=Add(D[j-a],Mult(h2,b+1));
					D[j+1]=Sub(D[j+1],Mult(h2,a+b+2));
					D[j+b+2]=Add(D[j+b+2],Mult(h2,a+1));
				}
			// grey
			ansG=Mult(cnt,sum);
			// retract blue
			a=b=0;
				Fox(i,M)
				{
					a=Add(a,D[i]);
					b=Add(b,a);
					ansR=Sub(ansR,Mult(b,H[i]));
				}
			// black
			ansB=Sub(Mult(cnt,Mult(N,M)),Add(ansW,Add(ansG,ansR)));
			// output
			printf("Case #%d: %d %d %d %d\n",t,Sub(0,ansB),Sub(0,ansW),Sub(0,ansG),Sub(0,ansR));
		}
	return(0);
}
