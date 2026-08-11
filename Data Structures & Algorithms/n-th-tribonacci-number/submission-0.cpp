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
        return tribo(dp,n);
    }
};