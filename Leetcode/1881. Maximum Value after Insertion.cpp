class Solution {
public:
    string maxValue(string n, int x) {
        bool isNegative=false;
        bool isInsert=false;
        string ans = "";
        for(int i=0;i<n.length();++i) {
            if(n[i]=='-') {
                isNegative=true;
            } else if(!isInsert && isNegative && n[i]-'0'>x) {
                ans+='0'+x;
                isInsert=true;
            } else if(!isInsert && !isNegative && n[i]-'0'<x) {
                ans+='0'+x;
                isInsert=true;
            }
            ans+=n[i];
        }
        if(!isInsert){
            ans+='0'+x;
        }
        return ans;
    }
};
