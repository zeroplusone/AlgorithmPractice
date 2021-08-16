class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int ans=-1;
        vector<bool> v(4, false);
        backtracking(0, 0, arr, v, ans);
        if(ans==-1) {
            return "";
        } else {
            int h=ans/100;
            int m=ans%100;
            string time="";
            if(h<10) {
                time.push_back('0');
                time.append(to_string(h));
            } else {
                time.append(to_string(h));
            }
            time.push_back(':');
            if(m<10) {
                time.push_back('0');
                time.append(to_string(m));
            } else {
                time.append(to_string(m));
            }
            
            return time;    
        }
    }
    
    void backtracking(int now, int sum, vector<int>& arr, vector<bool>& v, int& ans) {
        if(now==4) {
            if(sum/100<24 && sum%100<60) {
                ans=max(sum, ans);    
            }
            return;
        }
        for(int i=0;i<4;++i) {
            if(!v[i]) {
                v[i]=true;
                backtracking(now+1, sum*10+arr[i], arr, v, ans);
                v[i]=false;
            }
        }
    }
};
