#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAXN 20
char C[MAXN], J[MAXN];

int main(){
	int t, tNum;
    int i,j,len,pro;
    int a,b;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d: ", t);
		scanf("%s %s",C,J);
        len=strlen(C);
        a=0;b=0;
        for(i=0;i<len;++i){
            if(C[i]=='?' && J[i]!='?')   pro=1;
            else if(C[i]!='?' && J[i]=='?') pro=2;
            else if(C[i]=='?' && J[i]=='?') pro=3;
            else    pro=0;
            switch(pro){
                case 0:
                    break;
                case 1:
                    if(a>b){
                        C[i]='0';
                    }else if(a<b){
                        C[i]='9';
                    }else{
                        C[i]=J[i];
                    }
                    break;
                case 2:
                    if(a>b){
                        J[i]='9';
                    }else if(a<b){
                        J[i]='0';
                    }else{
                        J[i]=C[i];
                    }
                    break;
                case 3:
                    if(a>b){
                        C[i]='0';
                        J[i]='9';
                    }else if(a<b){
                        C[i]='9';
                        J[i]='0';
                    }else{
                        C[i]='0';
                        J[i]='0';
                    }
                    break;
            }
            a=a*10+C[i]-'0';
            b=b*10+J[i]-'0';
        }
		printf("%s %s\n",C,J);
	}
	return 0;
}
