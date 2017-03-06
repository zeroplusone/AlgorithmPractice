#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define PI acos(-1)

int main(){
    int T,tt,p,x,y;
    double dis,pangle,cx,cy,cangle;
    scanf("%d",&T);
    for(tt=1;tt<=T;++tt){
        printf("Case #%d: ",tt);
        scanf("%d%d%d",&p,&x,&y);
        dis = sqrt((x-50)*(x-50)+(y-50)*(y-50));
        if(dis>50){
            printf("white\n");
        }else{
            pangle=p*2*PI/(double)100;
            cx=50+(double)((x-50)*50)/dis;
            cy=50+(double)((y-50)*50)/dis;
            cangle=acos((50*50*2-((cx-50)*(cx-50)+(cy-100)*(cy-100)))/(2*50*50));
            //cout<<cx<<" "<<cy<<" "<<pangle<<" "<<cangle<<endl;
            if(cx<50)
                cangle=2*PI-cangle;
            if(cangle<=pangle)
                printf("black\n");
            else
                printf("white\n");

        }
    }
}