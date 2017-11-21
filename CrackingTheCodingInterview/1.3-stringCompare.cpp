#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool compareString(char str1[], char str2[]){
    int len1 = strlen(str1), len2 = strlen(str2);
    if(len1 != len2)
        return false;
    sort(str1, str1+strlen(str1));
    sort(str2, str2+strlen(str2));
    int i;
    for(i=0;i<len1;++i){
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}

bool compareString2(char str1[], char str2[]){
    int len1 = strlen(str1), len2 = strlen(str2);
    if(len1 != len2)
        return false;
    int cnt[257];
    memset(cnt, 0, sizeof(cnt));
    int i;
    for(i=0;i<len1;++i){
        cnt[str1[i]]++;
        cnt[str2[i]]--;
    }
    for(i=0;i<257;++i){
        if(cnt[i]!=0)
            return false;
    }
    return true;
}

int main(){
    char str1[] = "abc";
    char str2[] = "cab";
    if(compareString(str1, str2))
        printf("YES");
    else
        printf("NO");
    if(compareString2(str1, str2))
        printf("YES");
    else
        printf("NO");
    return 0;
}