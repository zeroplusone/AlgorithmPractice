#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#define MAXN 250
int arr[MAXN][MAXN];
string s1, s2;
int s1l,s2l;
int s1_length,s2_length;

bool LCS()
{
    for (int i=0; i<=s1_length; i++) arr[i][0] = 0;
    for (int j=0; j<=s2_length; j++) arr[0][j] = 0;

    for (int i=1; i<=s1_length; i++){
        for (int j=1; j<=s2_length; j++){
            if (s1[i] == s2[j] || s1[i]=='*' || s2[j]=='*'){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    for (int i=1; i<=s1_length; i++){
        for (int j=1; j<=s2_length; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<s1_length<<" "<<s2_length<<" "<<s1l<<" "<<s2l<<" "<<endl;
    if(arr[s1_length][s2_length]>=s1_length && arr[s1_length][s2_length]>=s2_length)
        return true;
    else
        return false;
    //cout << "LCS的長度是" << arr[s1_length][s2_length];
}

int main()
{
    int casenum;
    bool ans;
    int i,j,k;
    string in;
    scanf("%d",&casenum);

    for(int cc=1;cc<=casenum;++cc)
    {
        printf("Case #%d: ",cc);
        ans=true;
        cin>>in;
        s1l=in.length();
        s1="";
        for(i=0;i<in.length();++i){
            if(in[i]=='*'){
                s1+="****";

            }
            else
                s1+=in[i];
        }
        s1_length=s1.length();
        cin>>in;
        s2="";
        s2l=in.length();
        for(i=0;i<in.length();++i){
            if(in[i]=='*'){
                s2+="****";
            }
            else
                s2+=in[i];
        }
        s2_length=s2.length();
        cout<<s1<<" "<<s2<<endl;
        ans=LCS();
        if(ans)
            printf("TRUE");
        else
            printf("FALSE");
    }
    return 0;
}
