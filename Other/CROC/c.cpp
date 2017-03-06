#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<map>
#include<cstring>
using namespace std;

struct pathSet{
    set<string> path;
};
typedef struct pathSet pathSet;
#define MAXSTR 50

int main(){
    int n;
    map<string,pathSet> hostname;
    map<stromg,pathSet>::iterator it;
    string in,h,p;
    char* pch,str[MAXSTR];i
    while(scanf("%d",&n)!=EOF){
        hostname.clear();
        while(n--){
            cin>>in;
            in=in.substr(7,in.length()-7);
            strcpy(str,in.c_str());
            pch=strtok(str,"\n/");
            h.assign(pch);
            pch=strtok(NULL,"\n");
            if(pch==NULL)
                p.assign("!");
            else
                p.assign(pch);
            hostname[h].path.insert(p);
        }
        for(it=hostname.begin();it!=hostname.end();++it){
            
        }
    }
    return 0;
}
