class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int ans = 0;
        int l = 0; 
        int r = 1;
        while(r < prices.size()){
            profit = prices[r] - prices[l];
            if(profit <= 0){
                l = r;
                r++;
            }
            else{
                ans = max(ans, profit);
                r++;
            }
        }
        return ans;
    }
};
