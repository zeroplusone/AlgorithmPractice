#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

#define MAXN 200010

struct event{
    long long int now;
    bool type;
    int index;
    // arrival = false, departure = true;
    bool operator<(const event& tmp)const{
        return tmp.now==now?!type:tmp.now<now;
    }
}e,tmp;
int d[MAXN];
long long int ans[MAXN];
typedef struct event event;

int main(){
    int n,b;
    int i;
    int ti;
    bool isBusy=false;
    priority_queue<event> que;
    queue<int> waitQue;
    while(scanf("%d%d",&n,&b)!=EOF){
        while(!que.empty()) que.pop();
        while(!waitQue.empty()) waitQue.pop();
        for(i=0;i<n;++i){
            scanf("%d%d",&ti,&d[i]);
            e.type=false;
            e.now=ti;
            e.index=i;
            que.push(e);
        }
        isBusy=false;
        while(!que.empty()){
            e=que.top();
            //printf("%c :%lld, busy %c, queue %lu\n",e.type?'a':'d',e.now, isBusy?'T':'F',waitQue.size());
//            if(!waitQue.empty())    printf("wait queue %d\n",waitQue.front());
            que.pop();
            if(e.type){
            //departure
                ans[e.index]=e.now;
                if(waitQue.size()==0){
                    isBusy=false;
                }else{
                    tmp.type=true;
                    tmp.now=e.now+d[waitQue.front()];
                    tmp.index=waitQue.front();
                    que.push(tmp);
                    //printf("pop %d\n",waitQue.front());
                    waitQue.pop();
                    isBusy=true;
                }
            }else{
            //arrival
                if(!isBusy){
                    tmp.type=true;
                    tmp.now=e.now+d[e.index];
                    tmp.index=e.index;
                    que.push(tmp);
                    isBusy=true;
                }else{
                    if(waitQue.size()==b){
                        ans[e.index]=-1;
                    }else{
                        waitQue.push(e.index);
                    }
                }
            }
        }
        printf("%I64d",ans[0]);
        for(i=1;i<n;++i)
            printf(" %I64d",ans[i]);
        printf("\n");
    }
    return 0;
}
