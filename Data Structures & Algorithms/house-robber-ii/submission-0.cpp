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
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());
        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);
        int ans1 = robbery(temp1, temp1.size() - 1, dp1);
        int ans2 = robbery(temp2, temp2.size() - 1, dp2);
        return max(ans1, ans2);
    }
};
