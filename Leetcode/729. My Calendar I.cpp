class MyCalendar {
public:
    MyCalendar() {
        st=vector<int>(0);
        en=vector<int>(0);
    }
    
    bool book(int start, int end) {
        int index = upper_bound(en.begin(), en.end(), start)-en.begin();
        if(index==en.size() || st[index]>=end) {
            st.insert(st.begin()+index, start);
            en.insert(en.begin()+index, end);
            return true;
        } else {
            return false;
        }
    }
private:
    vector<int> st;
    vector<int> en;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
