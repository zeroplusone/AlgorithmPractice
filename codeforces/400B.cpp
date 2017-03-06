#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 110000
bool isprime[MAXN];
int prime[MAXN];
int ans[MAXN];
int coun;

void makeprime()
{
    int i,j;
    memset(isprime,true,sizeof(isprime));
    isprime[0]=false;
    for(i=2;i<=sqrt(MAXN);++i)
    {
        if(isprime[i])
        {
            for(j=i*i;j<MAXN;j+=i)
            {
                isprime[j]=false;   
            }
        }
    }
}

int main()
{
    int n;
    makeprime();
    scanf("%d",&n);
    memset(ans,1,sizeof(ans));
    if(n<=2)
        cout<<"1"<<endl;
    else
        cout<<"2"<<endl;
    for(int i=2;i<2+n;++i){
        if(i==2)
            cout<<"1";
        else
        {
            if(isprime[i])
                cout<<" 1";
            else
                cout<<" 2";
        }
    }
    cout<<endl;
    return 0;
}