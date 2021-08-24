class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> n1=to_num(num1);
        pair<int, int> n2=to_num(num2);

        int a=n1.first*n2.first+(-1)*(n1.second*n2.second);
        int b=n1.second*n2.first+n2.second*n1.first;
        string ans=to_string(a)+"+"+to_string(b)+"i";
        return ans;
    }
    
    pair<int, int> to_num(string s) {
        int a, b;
        string in="";
        int i=0;
        while(s[i]!='+') {
            in+=s[i];
            i++;
        }
        a=stoi(in);
        i++;
        in="";
        while(s[i]!='i') {
            in+=s[i];
            i++;
        }
        b=stoi(in);
        return make_pair(a, b);
    }
};
