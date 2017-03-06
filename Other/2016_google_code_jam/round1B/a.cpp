#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 2100
char str[MAXN];
int ans[MAXN];
int coun[26];
string num[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
struct Number{
    int n;
    char c;
}a[10];

int main(){
	int t, tNum;
    int i,j,ansN,len,len2;
    a[0].n=0; a[0].c='Z';
    a[1].n=2; a[1].c='W';
    a[2].n=6; a[2].c='X';
    a[3].n=8; a[3].c='G';
    a[4].n=3; a[4].c='H';
    a[5].n=7; a[5].c='S';
    a[6].n=4; a[6].c='U';
    a[7].n=5; a[7].c='V';
    a[8].n=1; a[8].c='O';
    a[9].n=9; a[9].c='N';
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d: ", t);
        getchar();
		scanf("%s",str);
        len=strlen(str);
        memset(coun, 0, sizeof(coun));
        for(i=0;i<len;++i)
            coun[str[i]-'A']++;
        ansN=0;
        
        for(i=0;i<10;++i){
            while(coun[a[i].c-'A']!=0){
                //cout<<a[i].n;
                ans[ansN]=a[i].n;
                ansN++;
                len2=num[a[i].n].length();
                for(j=0;j<len2;++j)
                    coun[num[a[i].n][j]-'A']--;
            }
        }
        
        sort(ans,ans+ansN);
        for(i=0;i<ansN;++i)
            printf("%d",ans[i]);
        printf("\n");
	}
	return 0;
}
