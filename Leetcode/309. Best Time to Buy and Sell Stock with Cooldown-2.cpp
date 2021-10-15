class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        

        int sold=-1e9;
        int held=-1e9;
        int wait=0;

        for(int i=0;i<n;++i) {
            int tmp=sold;
            sold=max(sold, held+prices[i]);
            held=max(held, wait-prices[i]);
            wait=max(wait, tmp);
        }
        
        return max(sold, max(held, wait));
    }
};
