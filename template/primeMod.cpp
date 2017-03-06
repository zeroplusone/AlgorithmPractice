#define PR pair<int,int>
#define mp make_pair
#define x first
#define y second

#define MOD 1000000007

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