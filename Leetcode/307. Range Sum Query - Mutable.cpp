class NumArray {
public:
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        root = build(0, nums.size()-1);
    }
    
    void update(int index, int val) {
        cover(root, 0, nums.size()-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(root, 0, nums.size()-1, left, right);
    }
private:
    vector<int> nums;

    struct Node {
        int val;
        int indexl, indexr;
        Node *l, *r;
        
        void update(int v) {
            val=v;
        }
        
        void pull() {
            val=l->val+r->val;
        }
        
        Node(int v): val(v), l(nullptr), r(nullptr){}
        Node(): val(0), l(nullptr), r(nullptr){}
    };
    Node* root;
    
    Node* build(int L, int R) {
        if(L==R) {
            return new Node(nums[L]);
        }
        
        int mid=(L+R)>>1;
        Node* ret = new Node();
        ret->l=build(L, mid);
        ret->r=build(mid+1, R);
        ret->pull();
        return ret;
    }
    
    int query(Node* now, int L, int R, int x, int y) {
        if(y<L || x>R) {
            // no overlap
            return 0;
        } else if(x<=L && y>=R) {
            // complete overlap
            return now->val;
        } else {
            int mid = (L+R)>>1;
            return query(now->l, L, mid, x, y)+query(now->r, mid+1, R, x, y);
        }
    }
    
    void cover(Node* now, int L, int R, int x, int v) {
        if(L==R) {
            now->val=v;
            return;
        } 
        int mid=(L+R)>>1;
        if(x<=mid) {
            cover(now->l, L, mid, x, v);
        }else {
            cover(now->r, mid+1, R, x, v);
        }
        now->pull();
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
