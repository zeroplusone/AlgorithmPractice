class Solution {
public:
    struct Trie{
        vector<Trie*> child;
        vector<string> w;
        vector<int> index;
        Trie(): child(vector<Trie*>(26, nullptr)), w(vector<string>(0)){};
    };

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* root = new Trie();
        for(int i=0;i<words.size();++i) {
            string reverse (words[i].rbegin(), words[i].rend());
            root->w.push_back(reverse);
            root->index.push_back(i);
            Trie* now = root;
            for(int j=0;j<reverse.length();++j) {
                if(now->child[reverse[j]-'a']==nullptr) {
                    Trie* newNode = new Trie();
                    now->child[reverse[j]-'a']=newNode;
                    now=newNode;
                } else {
                    now=now->child[reverse[j]-'a'];
                }
                if(j!=reverse.length()-1) {
                    now->w.push_back(reverse.substr(j+1));
                } else {
                    now->w.push_back("");
                }
                now->index.push_back(i);
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<words.size();++i) {
            Trie* now=root;
            int j=0;
            for(;j<words[i].size();++j) {
                for(int k=0;k<now->w.size();++k) {
                    if(i!=now->index[k] && now->w[k]=="") {
                        if(isPalindrome(words[i].substr(j))) {
                            ans.push_back({i, now->index[k]});
                        }
                    }
                }
                if(now->child[words[i][j]-'a']==nullptr) {
                    break;
                } else {
                    now=now->child[words[i][j]-'a'];
                }
            }
            if(j!=words[i].size()) {
                continue;
            } else{
                for(int k=0;k<now->w.size();++k) {
                    if(i!=now->index[k] && isPalindrome(now->w[k])) {
                        ans.push_back({i, now->index[k]});
                    }
                }
            }
        }

        return ans;
    }
    
    bool isPalindrome(string str) {
        int n=str.length();
        for(int i=0;i<n/2;++i) {
            if(str[i]!=str[n-i-1]) {
                return false;
            }
        }
        return true;
    }
};
