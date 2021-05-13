class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        set<string> ans;
        string first="", second=s.substr(1, s.length()-2);
        for(int i=1;i<s.length()-2;++i){
            first+=s[i];
            second=second.substr(1, second.length()-1);
            solve(first, second, ans);
        }
        return vector(ans.begin(), ans.end());
    }
    
    void solve(string first, string second, set<string>& ans) {
        string x, y;
        for(int i=0;i<first.length();++i) {
            x=getDecimal(i, first);
            if(x=="") {
                continue;
            }
            for(int j=0;j<second.length();++j) {
                y=getDecimal(j, second);
                if(y==""){
                    continue;
                }
                ans.insert("("+x+", "+y+")");
            }
        }
    }
    
    string getDecimal(int index, string str) {
        if(index==0) {
            if(str.length()>1 && str[0]=='0') {
                return "";
            } else {
                return str;   
            }
        }else {
            string pre=str.substr(0, index);
            string post=str.substr(index, str.length()-index);
            if((pre.length()>1 && pre[0]=='0') || post[post.length()-1]=='0') {
                return "";
            } else {
                return pre+"."+post;    
            }
        }
    }
    
    
};
