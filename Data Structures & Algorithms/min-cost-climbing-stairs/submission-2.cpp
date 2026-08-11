class Solution {
public:
    int f(int idx, vector<int>& cost, vector<int>& dp){
        if(idx <= 1) return 0;
        if(dp[idx] != -1) return dp[idx];

        int left = cost[idx-2] + f(idx - 2, cost, dp);
        int right = cost[idx-1] + f(idx - 1, cost,dp);
       
        return dp[idx] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return f(n, cost, dp);
    }
};
