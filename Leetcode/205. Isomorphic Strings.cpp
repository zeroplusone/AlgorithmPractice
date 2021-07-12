class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> smap(256, 0), tmap(256, 0);
        int cnt=1;
        for(int i=0;i<s.length();++i) {
            int sn=s[i];
            int tn=t[i];
            if(smap[sn]==0 && tmap[tn]==0) {
                smap[sn]=cnt;
                tmap[tn]=cnt;
                cnt++;
            } else if(smap[sn]!=tmap[tn]) {
                return false;
            }
        }
        return true;
    }
};
