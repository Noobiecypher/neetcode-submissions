class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int l = 0;
        int r = 0;
        int current = nums[0];
        int n = nums.size();
        int count = 1;

        while(r < n) {

            while(r < n && nums[r] == current) {
                r++;
            }

            if(r < n) {
                current = nums[r];
                count++;
                l++;
                nums[l] = nums[r];
            }
        }

        return count;
    }
};