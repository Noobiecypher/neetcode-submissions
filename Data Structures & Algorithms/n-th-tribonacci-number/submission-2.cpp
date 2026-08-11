class Solution {
public:
    int tribo(vector<int>&dp, int idx){
        if(idx <= 0) return 0;
        if(idx == 1 || idx == 2) return 1;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = tribo(dp,idx - 1) + tribo(dp,idx - 2) + tribo(dp,idx - 3);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n ; i++){
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};