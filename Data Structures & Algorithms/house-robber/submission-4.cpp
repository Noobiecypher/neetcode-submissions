class Solution {
public:
    int robbery(vector<int>& nums, int i, vector<int> &dp){
        if (i < 0) return 0;
        if(i == 0) return nums[0];
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + robbery(nums, i-2, dp);
        int notpick = robbery(nums, i-1, dp);
        return dp[i] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robbery(nums, nums.size() - 1, dp);
    }
};
