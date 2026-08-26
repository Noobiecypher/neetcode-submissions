class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum < 0){
                maxSum = max(sum, maxSum);
                sum = 0;
                continue;
            }
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
