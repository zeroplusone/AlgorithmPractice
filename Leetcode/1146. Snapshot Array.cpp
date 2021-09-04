class SnapshotArray {
public:
    SnapshotArray(int length) {
        snaps=vector<vector<pair<int, int>>>(length, vector<pair<int, int>>{make_pair(0, 0)});
        current=0;
    }
    
    void set(int index, int val) {
        int n=snaps[index].size();
        if(snaps[index][n-1].first==current) {
            snaps[index][n-1].second=val;
        } else {
            snaps[index].push_back(make_pair(current, val));
        }
    }
    
    int snap() {
        current++;
        return current-1;
    }
    
    int get(int index, int snap_id) {
        int n=snaps[index].size();
        int l=0, r=n-1;

        while(l<r) {
            int mid=(l+r+1)>>1;
            if(snaps[index][mid].first<=snap_id) {
                l=mid;    
            } else {
                r=mid-1;
            }
        }
        return snaps[index][r].second;
    }
    
    vector<vector<pair<int, int>>> snaps;
    int current;
};
// 2 4
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
