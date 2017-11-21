#include<cstring>
#include<cstdio>
using namespace std;


bool isRepeatedChar(char str[]){
    if(strlen(str)>256)
        return false;
    bool isVal[256];
    memset(isVal, false, sizeof(isVal));
    int i;
    for(i=0;i<strlen(str);++i){
        if(isVal[(int)str[i]])
            return false;
        else
            isVal[(int)str[i]]=true;
    }
    return true;
}

bool isRepeatedCharByBitVector(char str[]){
    if(strlen(str)>256)
        return false;
    int isVal=0;
    int i;
    for(i=0;i<strlen(str);++i){
        if((isVal &  (1<<str[i])) > 0)
            return false;
        else
            isVal |= 1<<str[i];
    }
    return true;
}

int main(){
    char str[] = "asdf";
    //if(isRepeatedChar(str))
    if(isRepeatedCharByBitVector(str))
        printf("No");
    else
        printf("Yes");
    return 0;
}