class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = (l + r)/2;
            while(l < r && nums[mid] == nums[l] && nums[l] == nums[r]){
                l++;
                r--;
            }
            if(nums[mid] == target) return true;
            if(nums[mid] >= nums[l]){
                if(target >= nums[l] && target <= nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};