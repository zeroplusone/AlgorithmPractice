class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans(0);
 
        for(int i=0;i<10*target.size();++i) {
            int j;
            for(j=0;j<=target.size()-stamp.size();++j) {
                int k;
                int match=0, qcnt=0;
                for(k=0;k<stamp.size();++k) {

                    if(stamp[k]==target[j+k]) {
                        match++;
                    } else if(target[j+k]=='?') {
                        qcnt++;
                    } else {
                        break;
                    }   
                }

                if(qcnt!=stamp.size() && qcnt+match==stamp.size()) {
                    ans.push_back(j);
                    for(int l=0;l<stamp.size();++l) {
                        target[j+l]='?';
                    }
                    break;
                }
            }
            int m;
            for(m=0;m<target.size();++m) {
                if(target[m]!='?'){
                    break;
                }
            }

            if(j==target.size()-stamp.size()+1 || m==target.size()) {
                break;
            }
        }
        
        int m;
        for(m=0;m<target.size();++m) {
            if(target[m]!='?'){
                break;
            }
        }
        if(m!=target.size()) {
            ans.clear();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

};
