class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> al;
        for(auto c:sentence) {
            al.insert(c);
        }
        return al.size()==26;
    }
};
