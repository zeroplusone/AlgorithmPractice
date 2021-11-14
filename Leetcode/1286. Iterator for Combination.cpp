class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        ans=vector<string>(0);
        backtracking(0, combinationLength, characters, "");
        index=0;
    }
    
    void backtracking(int now, int& n, string& str, string nowstr) {
        if(nowstr.length()==n) {
            ans.push_back(nowstr);
            return;
        }
        if(now>=str.length()) {
            return;
        }

        backtracking(now+1, n, str, nowstr+str[now]);
        backtracking(now+1, n, str, nowstr);
    }
    
    string next() {
        index++;
        return ans[index-1];
    }
    
    bool hasNext() {
        return index<ans.size();
    }
    
    int index;
    vector<string> ans;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
