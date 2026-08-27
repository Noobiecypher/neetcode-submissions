class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int masum = 0;
        int maxSum = INT_MIN;
        int misum = 0;
        int minSum = INT_MAX;
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            masum = max(masum + nums[i], nums[i]);
            maxSum = max(masum, maxSum);
            misum = min(misum + nums[i], nums[i]);
            minSum = min(misum, minSum);
        }
        if(maxSum < 0){
            return maxSum;
        }
        return max(maxSum, total - minSum);
    }
};