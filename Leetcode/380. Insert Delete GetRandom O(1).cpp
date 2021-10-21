class RandomizedSet {
public:
    RandomizedSet() {
        v=vector<int>(0);
        vsize=0;
    }
    
    bool insert(int val) {
        if(m.count(val)==0) {
            m[val]=vsize;
            if(vsize+1>v.size()) {
                v.resize(vsize+1);
            }
            v[vsize]=val;
            vsize++;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if(m.count(val)==0) {
            return false;
        } else {
            v[m[val]]=v[vsize-1];
            m[v[vsize-1]]=m[val];
            m.erase(val);
            vsize--;
            return true;
        }
    }
    
    int getRandom() {
        int r = rand()%vsize;
        return v[r];
    }
    
    unordered_map<int, int> m;
    vector<int> v;
    int vsize;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
