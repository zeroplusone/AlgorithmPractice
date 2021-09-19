class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        vector<char> ops(num.length(), ' ');
        // backtracking(0, ops, num, target, ans);
        backtracking(0, '+', 0, '+', 0, ops, num, target, ans);
        return ans;
    }

    void backtracking(int now, char last, long long int lastn, char cur, long long int sum, vector<char>& ops, string& num, int& target, vector<string>& ans) {

        string n="";
        int end=num[now]=='0'?now+1:num.length();
        for(int i=now;i<end;++i) {
            n+=num[i];
            long long int newn=stoll(n);
            long long int newsum=sum;
            char newlast=cur;
            if(cur=='+'||cur=='-') {
                newsum+=cur=='+'?newn:(-1)*newn;
            } else if(cur=='*') {
                newsum+=last=='+'?(-1)*lastn:lastn;
                newn*=lastn;
                newsum+=last=='+'?newn:(-1)*newn;
                newlast=last;
            }
            if(i==num.length()-1) {
                if(newsum==target) {
                    ans.push_back(buildExp(ops, num));
                }
            } else {
                ops[i]='*';
                backtracking(i+1, newlast, newn, '*', newsum, ops, num, target, ans);
                ops[i]='+';
                backtracking(i+1, newlast, newn, '+', newsum, ops, num, target, ans);
                ops[i]='-';
                backtracking(i+1, newlast, newn, '-', newsum, ops, num, target, ans);
                ops[i]=' ';
            }
        }
        
        
        
    }
    
    string buildExp(vector<char>& ops, string& num) {
        string ret="";
        for(int i=0;i<num.length();++i) {
            ret+=num[i];
            if(i!=num.length()-1 && ops[i]!=' ') {
                ret+=ops[i];
            }
        }
        return ret;
    }
};
