class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m;
        m['0']='0';
        m['1']='1';
        m['6']='9';
        m['9']='6';
        m['8']='8';
        
        int n=num.length();
        for(int i=0;i<n/2;++i) {
            if(m[num[i]]!=num[n-i-1]) {
                return false;
            }
        }

        if(n%2==1) {
            if(num[n/2]!='0'&&num[n/2]!='1'&&num[n/2]!='8') {
                return false;
            }
        }
        return true;
    }
};
