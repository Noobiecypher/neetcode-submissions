class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(pq.empty()) pq.push(prices[i]);
            else if(prices[i] > pq.top()){
                int profit = prices[i] - pq.top();
                pq.pop();
                maxProfit += profit;
                while(!pq.empty()) pq.pop();
                pq.push(prices[i]);
            }
            else if(prices[i] == pq.top()){
                continue;
            }
            else{
                pq.push(prices[i]);
            }
        }
        return maxProfit;
    }
};