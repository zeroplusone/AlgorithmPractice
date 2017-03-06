#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define MAXC 500
long long int c[MAXC][MAXC];

long long int C(int a,int b)
{
    if(a>=0 && b>=0 && c[a][b])
        return c[a][b];
    else if(a==b)
        c[a][b]=1;
    else if(a<b)
        c[a][b]=0;
    else if(a<=1)
        c[a][b]=1;
    else if(b==1)
        c[a][b]=a;
    else if(b==0)
        c[a][b]=1;
    else
    {
        int tmp=b;
        if(b*2>a)
            tmp=a-b;
        c[a][b]=C(a-1,tmp)+C(a-1,tmp-1);
    }
    return c[a][b];
}

long long int H(int a,int b){
    if(b<0){
        return 0;
    }
    return C(a+b-1,b);
}

double getProbability(int time,int side,int z,int hp){
    long long int total=pow(side,time);
    int maxV=side*time+z;
    int minV=time+z;
    int minus;
    long long int suc=0;
    if(minV>=hp){
        return 1;
    }
    for(int i=hp;i<=maxV;++i){
        minus=1;
        suc+=H(time,i-z-time);
        while(i-z-side*minus>0){
            if(minus%2==1){
                suc-=C(time,minus)*H(time,i-z-time-side*minus);
            }else{
                suc+=C(time,minus)*H(time,i-z-time-side*minus);
            }
            minus++;
        }
    }
    printf("%lld %lld\n",total, suc);
    return suc/(double)total;
}

int main(){
    int tt,T,hp,S,i;
    int side,time,z,pos;
    double ans,p;
    string s;
    memset(c,0,sizeof(c));
    scanf("%d",&T);
    for(tt=1;tt<=T;++tt){
        printf("Case #%d: ",tt);
        scanf("%d%d",&hp,&S);
        ans=0;
        for(i=0;i<S;++i){
            cin>>s;
            z=0;
            time=stoi(s.substr(0,s.find("d")));
            s.erase(0,s.find("d")+1);
            if((pos=s.find("+"))!=string::npos){
                side=stoi(s.substr(0,pos));
                s.erase(0,pos+1);
                z=stoi(s);
            }else if((pos=s.find("-"))!=string::npos){
                side=stoi(s.substr(0,pos));
                s.erase(0,pos+1);
                z=stoi(s)*(-1);
            }else{
                side=stoi(s);
            }
            p=getProbability(time,side,z,hp);
            ans=p>ans?p:ans;
        }
        printf("%lf\n",ans);
    }
}
