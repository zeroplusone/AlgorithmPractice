#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 500
int x,y;
int con[MAX][MAX];
int vy[MAX];
int xto[MAX],yto[MAX];

bool matching(int nowx)
{
     for(int l=0;l<y;++l)
     {
             if( con[nowx][l] && vy[l]==0 )
             {
                 vy[l]=1;
                 if( yto[l]==-1 || matching(yto[l]) )
                 {
                        xto[nowx]=l;
                        yto[l]=nowx;                        
                        return true;                   
                 }
             }
     }
     return false;     
}

int main()
{
    int c,max;
    scanf("%d",&c);
    for(int i=1;i<=c;++i)
    {
        max=0;
        scanf("%d %d",&x,&y);
        for(int j=0;j<x;++j)              
                for(int k=0;k<y;++k)               
                        scanf("%d",&con[j][k]);  
        for(int k=0;k<x;++k)               
                yto[k]=-1;   
        for(int k=0;k<y;++k)               
                xto[k]=-1;  

        for(int j=0;j<x;++j)
        {
                if(xto[j]==-1)
                {
                        for(int k=0;k<y;++k)               
                                vy[k]=0;
                        if(matching(j))                        
                                       max++;                
                }
        }                              
        printf("Case %d: ",i);
        printf("a maximum of %d nuts and bolts ",max);
        printf("can be fitted together\n");
        
    }

    return 0;   
}
