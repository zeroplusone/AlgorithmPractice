#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAXN 20
char C[MAXN], J[MAXN];
char ansC[MAXN],ansJ[MAXN];
long long int ans[3];

void update(int a,int b){
    ans[0]=abs(a-b);
    ans[1]=a; ans[2]=b;
    strcpy(ansC,C);
    strcpy(ansJ,J);
    //printf("update %s %s\n",C,J);
}
void backtracking(int now,int len){
    if(now==len){
        int a=0,b=0;
        for(int i=0;i<len;++i){
            a=a*10+C[i]-'0';
            b=b*10+J[i]-'0';
        }
        //printf("%s %s\n",C,J);
        if(ans[0]==-1){
            update(a,b);
            return;
        }
        if(abs(a-b)<ans[0]){
            update(a,b);
            return;
        }
        else if(abs(a-b)==ans[0] && a<ans[1]){
            update(a,b);
            return;
        }
        else if(abs(a-b)==ans[0] && a==ans[1] && b<ans[2]){
            update(a,b);
            return;
        }
        return;
    }
    int i,j;
    if(C[now]!='?' && J[now]!='?')
        backtracking(now+1,len);
    else if(C[now]=='?' && J[now]!='?'){
        for(i=0;i<10;++i){
            C[now]='0'+i;
            backtracking(now+1,len);
            C[now]='?';
        }
    }
    else if(C[now]!='?' && J[now]=='?'){
        for(i=0;i<10;++i){
            J[now]='0'+i;
            backtracking(now+1,len);
            J[now]='?';
        }
    }
    else{
        for(i=0;i<10;++i){
            for(j=0;j<10;++j){
                J[now]='0'+j;
                C[now]='0'+i;
                backtracking(now+1,len);
                J[now]='?';
                C[now]='?';
            }
        }
    }
}
int main(){
	int t, tNum;
    int i,j,len,pro;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d: ", t);
		scanf("%s %s",C,J);
        len=strlen(C);
        ans[0]=-1; ans[1]=-1; ans[2]=-1;
        backtracking(0,len);
		printf("%s %s\n",ansC,ansJ);
	}
	return 0;
}
