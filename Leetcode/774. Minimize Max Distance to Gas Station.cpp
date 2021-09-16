class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double l=0, r=0;
        for(int i=0;i<stations.size()-1;++i) {
            stations[i]=stations[i+1]-stations[i];
            if(stations[i]>r) {
                r=stations[i];
            }
        }
        
        while(r-l > 1e-6) {
            double mid=(l+r)/2.0;
            if(canbe(mid, stations, k)) {
                l=mid;
            } else {
                r=mid;
            }
        }
        return r;
    }
    
    bool canbe(double now, vector<int>& sta, int& k) {
        int cnt=0;
        for(int i=0;i<sta.size()-1;++i) {
            cnt+=ceil((sta[i]/now))-1;
        }
        return cnt>k;
    }
};
