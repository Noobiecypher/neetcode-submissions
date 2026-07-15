class Solution {
public:
    int climber(int n, vector<int> &dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = climber(n-1,dp) + climber(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climber(n, dp);
    }
};
