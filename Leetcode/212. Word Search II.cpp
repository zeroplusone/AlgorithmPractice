class Solution {
public:
    
    vector<vector<int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    struct Trie {
        vector<Trie*> next;
        Trie(): next(vector<Trie*>(26, nullptr)){};
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size();
        int n=board[0].size();

        Trie* root=new Trie();

        vector<vector<bool>> v(m, vector<bool>(n, false));
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                v[i][j]=true;
                buildTrie(root, i, j, board, v, 0);
                v[i][j]=false;
            }
        }

        vector<string> ans;
        for(int i=0;i<words.size();++i) {
            Trie* now=root;
            int j=0;
            for(;j<words[i].length();++j) {
                int ch=words[i][j]-'a';
                if(now->next[ch]==nullptr) {
                    break;
                }
                now=now->next[ch];
            }
            if(j==words[i].length()) {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
    
    void buildTrie(Trie* now, int x, int y, vector<vector<char>>& b, vector<vector<bool>>& v, int cnt) {
        if(cnt>=10) {
            return;
        }
        int ch=b[x][y]-'a';
        if(now->next[ch]==nullptr) {
            now->next[ch]=new Trie();
        }

        for(int i=0;i<4;++i) {
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            if(newx>=0 && newx<b.size() && newy>=0 && newy<b[0].size() && !v[newx][newy]) {
                v[newx][newy]=true;
                buildTrie(now->next[ch], newx, newy, b, v, cnt+1);
                v[newx][newy]=false;
            }
        }
    }

};
