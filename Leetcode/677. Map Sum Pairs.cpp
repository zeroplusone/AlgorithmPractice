class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int origin=0;
        if(keyMap.count(key)!=0) {
            origin=keyMap[key];
        }
        string sub="";
        for(int i=0;i<key.length();++i) {
            sub+=key[i];
            sumMap[sub]+=val-origin;
        }
        keyMap[key]=val;
    }
    
    int sum(string prefix) {
        return sumMap[prefix];
    }
private:
    unordered_map<string, int> keyMap;
    unordered_map<string, int> sumMap;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
