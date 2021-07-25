class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n=num.length();
        int index=0;
        while(index<n && change[num[index]-'0']<=(num[index]-'0')) {
            index++;
        }

        while(index<n && change[num[index]-'0']>=(num[index]-'0')) {
            num[index]='0'+change[num[index]-'0'];
            index++;
        }

        return num;
    }
};
