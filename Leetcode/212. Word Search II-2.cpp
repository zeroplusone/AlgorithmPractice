class Solution {
public:
    
    vector<vector<int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    struct Trie {
        vector<Trie*> next;
        bool end;
        Trie(): next(vector<Trie*>(26, nullptr)), end(false){};
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size();
        int n=board[0].size();

        Trie* root=new Trie();
        
        for(int i=0;i<words.size();++i) {
            Trie* now=root;
            for(int j=0;j<words[i].length();++j) {
                int ch=words[i][j]-'a';
                if(now->next[ch]==nullptr) {
                    now->next[ch]=new Trie();
                }
                now=now->next[ch];
            }
            now->end=true;
        }

        unordered_set<string> ans;
        vector<vector<bool>> v(m, vector<bool>(n, false));
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                v[i][j]=true;
                DFS(root, i, j, board, v, ans, "");
                v[i][j]=false;
            }
        }
        
        return vector<string>(ans.begin(), ans.end());
    }
    
    void DFS(Trie* now, int x, int y, vector<vector<char>>& b, vector<vector<bool>>& v, unordered_set<string>& ans, string str) {
        int ch=b[x][y]-'a';
        now=now->next[ch];
        if(now==nullptr) {
            return;
        }
        str+=b[x][y];
        if(now->end) {
            ans.insert(str);
        }

        for(int i=0;i<4;++i) {
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            if(newx>=0 && newx<b.size() && newy>=0 && newy<b[0].size() && !v[newx][newy]) {
                v[newx][newy]=true;
                DFS(now, newx, newy, b, v, ans, str);
                v[newx][newy]=false;
            }
        }
    }

};
