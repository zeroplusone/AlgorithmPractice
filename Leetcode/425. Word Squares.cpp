class Solution {
public:
    struct Trie {
        vector<Trie*> children;
        vector<string> w;
        Trie():children(vector<Trie*>(26, nullptr)), w(vector<string>(0)) {};
    };

    vector<vector<string>> wordSquares(vector<string>& words) {
        Trie* root=new Trie();
        unordered_map<int, vector<string>> cnt;
        for(int i=0;i<words.size();++i) {
            Trie* now=root;
            for(int j=0;j<words[i].length();++j) {
                int c=words[i][j]-'a';
                if(now->children[c]==nullptr) {
                    now->children[c]=new Trie();
                }
                now=now->children[c];
                now->w.push_back(words[i]);
            }
            root->w.push_back(words[i]);
            cnt[words[i].length()].push_back(words[i]);
        }
        
        vector<vector<string>> ans;
        for(auto c: cnt) {
            vector<string> ret(c.first);
            int n=c.first;
            backtracking(0, n, root, ans, ret);
        }
        return ans;
    }
    
    void backtracking(int now, int& n, Trie* root, vector<vector<string>>& ans, vector<string>& ret) {
        if(now==n) {
            ans.push_back(ret);
            return;
        }

        Trie* t=root;
        for(int i=0;i<now;++i) {
            int c=ret[i][now]-'a';
            if(t->children[c]==nullptr) {
                return;
            }
            t=t->children[c];
        }
        for(int i=0;i<t->w.size();++i) {
            ret[now]=t->w[i];
            backtracking(now+1, n, root, ans, ret);
            ret[now]="";
        }
        
    }
};
