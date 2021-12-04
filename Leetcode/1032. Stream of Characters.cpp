class StreamChecker {
public:
    
    struct Trie {
        unordered_map<char, Trie*> children;
        bool isEnd;
        Trie():isEnd(false){};
    };

    StreamChecker(vector<string>& words) {
        root=new Trie();
        for(int i=0;i<words.size();++i) {
            Trie* now=root;
            for(int j=words[i].length()-1;j>=0;--j) {
                if(now->children.count(words[i][j])==0) {
                    now->children[words[i][j]]=new Trie();
                }
                
                now=now->children[words[i][j]];
            }
            now->isEnd=true;
        }
        stream=vector<char>(0);
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        Trie* now=root;
        for(int i=stream.size()-1;i>=0&&!now->isEnd;--i) {
            if(now->children.count(stream[i])==0) {
                return false;
            } else {
                now=now->children[stream[i]];
            }
        }
        return now->isEnd;
    }
    
    Trie* root;
    vector<char> stream;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
