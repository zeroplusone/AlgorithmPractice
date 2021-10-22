class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();++i) {
            m[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto i: m) {
            pq.push(make_pair(i.second, i.first));
        }
        string ans="";
        while(!pq.empty()) {
            pair<int, char> t=pq.top();
            ans+=string(t.first, t.second);
            pq.pop();
        }
        return ans;
    }
};
