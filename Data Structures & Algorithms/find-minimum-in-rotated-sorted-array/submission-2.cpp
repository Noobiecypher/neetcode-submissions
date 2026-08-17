class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = INT_MAX;
        if(nums[l] < nums[r]) return nums[l];
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
                ans = min(ans,nums[mid]);
            }
            else{
                r = mid - 1;
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
    }
};
