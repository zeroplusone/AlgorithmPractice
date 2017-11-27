#include<iostream>
#include<cstring>

using namespace std;

void replace_force(char str[], int len){
    int i, j;
    char tmp1, tmp2;
    for(i=0;i<len;){
        if(str[i]==' '){
            str[i]='%';
            for(j=i+3;j<len;j+=2){
                tmp1=str[j];
                str[j]=str[i+1];
                str[i+1]=tmp1;
                if(j+1<len){
                    tmp2=str[j+1];
                    str[j+1]=str[i+2];
                    str[i+2]=tmp2;
                }
            }
            str[i+1]='2';
            str[i+2]='0';
            i+=3;
        }
        else
            i++;
    }
    str[len]='\0';
}

void replace_doubleSpace(char str[], int len){
    char cpy[200];
    strcpy(cpy, str);
    int i,j;
    for(i=0, j=0; j<len;){
        if(str[i]==' '){
            cpy[j++]='%';
            cpy[j++]='2';
            cpy[j++]='0';
            ++i;
        }else{
            cpy[j] = str[i];
            i++; j++;
        }
    }
    strcpy(str, cpy);
}

void replace_fromBack(char str[], int len){
    str[len]='\0';
    int i=strlen(str)-1, j=len-1;
    for(;i>=0;--i){
        if(str[i]==' '){
            str[j]='0';
            str[j-1]='2';
            str[j-2]='%';
            j-=3;
        }else{
            str[j--]=str[i];
        }
    }
}

int main(){
    char str[200];
    strcpy(str,"Mr John Smith");
    int space=0;
    for(int i=0;i<strlen(str);++i){
        if(str[i]==' ')
            space++;
    }
    int newlen = strlen(str)+2*space;
    replace_force(str, newlen);
    printf("%s", str);
    strcpy(str, "Mr John Smith");
    replace_doubleSpace(str, newlen);
    printf("%s", str);
    strcpy(str, "Mr John Smith");
    replace_fromBack(str,newlen);
    printf("%s", str);
    return 0;
}