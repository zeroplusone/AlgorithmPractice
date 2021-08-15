class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        if(m<n) {
            return "";
        }
        
        vector<int> cnt(52, 0);
        for(int i=0;i<n;++i) {
            cnt[toIndex(t[i])]++;
        }
        int st=0, ans=0, len=1e9;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> now(52, 0);
        
        for(int i=0;i<m;++i) {
            int index=toIndex(s[i]);

            if(cnt[index]==0 && pq.empty()) {
                st=i+1;
                continue;
            } else {
                now[index]++;
                pq.push(i);
                
                while(!pq.empty() && now[toIndex(s[st])]>cnt[toIndex(s[st])]) {
                    pq.pop();
                    now[toIndex(s[st])]--;
                    st=pq.top();
                }
            }

            bool found=true;
            for(int j=0;j<52;++j) {
                if(cnt[j]>now[j]) {
                    found=false;
                    break;
                }
            }
            if(found && i-st+1<len) {
                ans=st;
                len=i-st+1;
            }
        }
        
        return len==1e9?"":s.substr(ans, len);
    }
    
    int toIndex(char c) {
        if(c>='a' && c<='z') {
            return c-'a';
        }else {
            return c-'A'+26;
        }
        return 0;
    }
};
