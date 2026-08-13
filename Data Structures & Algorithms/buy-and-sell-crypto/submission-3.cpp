class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxProfit = 0;
        while(l <= r && r < prices.size()){
            int profit = 0;
            profit = prices[r] - prices[l];
            if(profit >= 0){
                r++;
                maxProfit = max(profit, maxProfit);
            }
            else{
                l++;
            }
        }
        return maxProfit;
    }
};
