#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXD 1100
int tmp[MAXD];
int d;

int findMin(int p[],int sum,int ans)
{
    printf("~%d %d\n",ans,sum);

    for(int i=0;i<d;++i)
        printf("%d ",p[i]);
    printf("\n");

    if(sum<=0)
    {
        return ans;
    }
    int sp,nsp,tsum,maxn,maxi,i;
    // non special time
    printf("nsp\n");
    tsum=sum;
    for(i=0;i<d;++i)
    {
        tmp[i]=p[i];
        if(tmp[i]!=0)
        {
            tmp[i]=tmp[i]-1;
            tsum-=1;
        }
    }
    nsp=findMin(tmp,tsum,ans+1);
    //special time
    printf("sp\n");
    tsum=sum;
    maxn=p[0];
    tmp[0]=p[0];
    maxi=0;
    for(i=1;i<d;++i)
    {
        tmp[i]=p[i];
        if(tmp[i]>maxn)
        {
            maxn=tmp[i];
            maxi=i;
        }
    }
    if(maxn==1)
        sp=MAXD;
    else
    {
        tsum=(maxn-1)/2;
        tmp[maxi]=(tmp[maxi]+1)/2;    
        sp=findMin(tmp,tsum,ans+1);
    }
    printf("!%d %d %d\n",sp,nsp,ans);
    return sp>nsp?nsp:sp;

}


int main()
{
    int tt,T;
    int i,sum;
    int p[MAXD];
    scanf("%d",&T);
    for(tt=1;tt<=T;++tt)
    {
        sum=0;
        scanf("%d",&d);
        for(i=0;i<d;++i)
        {
            scanf("%d",&p[i]);
            sum+=p[i];
        }
        printf("Case #%d: %d\n",tt,findMin(p,sum,0));
    }
    return 0;
}
