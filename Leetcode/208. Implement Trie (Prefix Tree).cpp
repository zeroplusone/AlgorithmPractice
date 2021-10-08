class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* now=root;
        for(int i=0;i<word.length();++i) {
            int ch=word[i]-'a';
            if(now->children[ch]==nullptr) {
                now->children[ch]=new TrieNode();
            } 
            now=now->children[ch];
        }
        now->exist=true;
    }
    
    bool search(string word) {
        TrieNode* now=root;
        for(int i=0;i<word.length();++i) {
            
            int ch=word[i]-'a';
            if(now->children[ch]==nullptr) {
                return false;
            }
            now=now->children[ch];
        }
        return now->exist;
    }
    
    bool startsWith(string prefix) {
        TrieNode* now=root;
        for(int i=0;i<prefix.length();++i) {
            int ch=prefix[i]-'a';
            if(now->children[ch]==nullptr) {
                return false;
            }
            now=now->children[ch];
        }
        return true;
    }
    
    struct TrieNode {
        vector<TrieNode*> children;
        bool exist;
        TrieNode(): children(vector<TrieNode*>(26, nullptr)), exist(false){};
    };
    
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
