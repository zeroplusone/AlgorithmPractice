#include<iostream>
#include<cstring>
using namespace std;

void reverse(char* str){

    int len=strlen(str);
    char* start=str;
    char* end=&str[len-1];
    char tmp;
    //int cnt=len/2;
    //while(cnt--){
    while(start<end){
        tmp=*start;
        *start=*end;
        *end=tmp;
        start++;
        end--;
    }
}

void reverseByRecursive(char* str){
    if(!strcmp(str,"\0")){
        return;
    }
    int len = strlen(str);
    char tmp = str[len-1];
    str[len-1]='\0';
    reverseByRecursive(str+1);
    str[len-1]=str[0];
    str[0]=tmp;
}

int main(){
    char str[] = "string";
    reverse(str);
    printf("%s\n",str);
    strcpy(str,"string");
    reverseByRecursive(str);
    printf("%s\n",str);
}