class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int minLength = INT_MAX;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                sum -= nums[l];
                minLength = min(minLength, i - l + 1);
                l++;
            }
        }
        return(minLength == INT_MAX)?0:minLength;
    }
};