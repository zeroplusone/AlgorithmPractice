class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> power;
        int num1, num2;
        for(int i=0;;++i){
            num1=pow(x,i);
            if(num1>bound) {
                break;
            }
            for(int j=0;;++j) {
                num2=pow(y,j);
                if(num1+num2>bound) {
                    break;
                }else{
                    power.insert(num1+num2);
                }
                
                if(y==1)
                    break;
            }
            if(x==1)
                break;
        }
        
        vector<int> ans(power.begin(), power.end());
        return ans;
    }
};
