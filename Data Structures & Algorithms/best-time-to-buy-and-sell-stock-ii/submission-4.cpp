class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int maxP = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > min){
                int profit = prices[i] - min;
                maxP += profit;
                min = prices[i];
            }

            else{
                min = prices[i];
            }
        }
        return maxP;
    }
};