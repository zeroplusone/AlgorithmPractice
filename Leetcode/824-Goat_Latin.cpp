/*********************
problem: 824. Goat Latin
https://leetcode.com/contest/weekly-contest-82/problems/goat-latin/
**********************/

class Solution {
public:
    string toGoatLatin(string S) {
        int index=1;
        bool vowel=true;
        char firstc;
        string ans="";
        for(int i=0;i<S.length();++i){
            
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o' || S[i]=='u' || S[i]=='A' || S[i]=='E' || S[i]=='I' || S[i]=='O' || S[i]=='U'){
                vowel=true;
            }else{
                vowel=false;
                firstc=S[i];
            }
            
            while(S[i]!=' ' && i!=S.length()){
                // cout<<"ans:"<<ans<<endl;
                if(vowel){
                    ans+=S[i];
                }else{
                    ans+=S[i+1];
                }
                i++;
            }
            
            if(!vowel){
                ans[ans.length()-1]=firstc;
            }
            ans+="ma";
            for(int j=0;j<index;++j){
                ans+='a';
            }
            if(S[i]==' ')
                ans+=' ';
            // cout<<"ans2:"<<ans<<endl;
            index++;
        }
        return ans;
    }
};