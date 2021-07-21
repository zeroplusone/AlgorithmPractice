class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.length();
        vector<int> sum(n, 0);

        int i=0, cnt=0;
        while(i<n&&dominoes[i]!='R') {i++;}
        for(;i<n;++i) {
            cnt=dominoes[i]=='R'?n:(dominoes[i]=='L'?0:(cnt>1?cnt-1:0));
            sum[i]=cnt;
        }
        i=n-1; cnt=0;
        while(i>=0&&dominoes[i]!='L') {i--;}
        for(;i>=0;--i) {
            cnt=dominoes[i]=='L'?-n:(dominoes[i]=='R'?0:(cnt<-1?cnt+1:0));
            sum[i]+=cnt;
        }
        
        for(int i=0;i<n;++i) {
            if(sum[i]==0) {
                dominoes[i]='.';
            } else if(sum[i]>0) {
                dominoes[i]='R';    
            } else {
                dominoes[i]='L';
            }
        }
        return dominoes;
    }
};
