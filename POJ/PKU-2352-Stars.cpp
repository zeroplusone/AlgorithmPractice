#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXX 32005
#define MAXN 15005

int level[MAXN];
int s[MAXX];

int lowbit(int in)
{
    return in&(-in);
}

int getsum(int end)
{
    int ans=0;
    while(end>0)
    {
        ans+=s[end];
        end-=lowbit(end);
    }
    return ans;
}

void change(int end,int delta)
{
    for(int i=end;i<MAXX;i+=lowbit(i))
        s[i]+=delta;
}

int main()
{
    int N,x,y,coun;
    scanf("%d",&N);
        memset(s,0,sizeof(s));
        memset(level,0,sizeof(level));
        coun=N;
        while(coun--)
        {
            scanf("%d %d",&x,&y);
            x++;
            level[getsum(x)]++;
            change(x,1);
        }
        for(int i=0;i<N;++i)
        {
            printf("%d\n",level[i]);
        }

    return 0;
}
