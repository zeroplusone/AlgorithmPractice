class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root=new TrieNode('a');
    }
    
    void insert(string key, int val) {
        int delta=val;
        if(keyMap.count(key)!=0) {
            delta-=keyMap[key];
        }
        TrieNode* now = root;
        for(int i=0;i<key.length();++i) {
            if(now->child[key[i]-'a']==nullptr) {
                now->child[key[i]-'a']=new TrieNode(key[i]);
            } 
            now=now->child[key[i]-'a'];
            now->sum=now->sum+delta;
        }
        keyMap[key]=val;
    }
    
    int sum(string prefix) {
        TrieNode* now=root;
        for(int i=0;i<prefix.length();++i) {
            now=now->child[prefix[i]-'a'];
            if(now==nullptr) {
                return 0;
            }
        }
        return now->sum;
    }
    
private:
    struct TrieNode{
        char c;
        vector<TrieNode*> child;
        int sum;
        TrieNode(char c):c(c), sum(0), child(vector<TrieNode*>(26, nullptr)){};
    };
    TrieNode* root;
    unordered_map<string, int> keyMap;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
