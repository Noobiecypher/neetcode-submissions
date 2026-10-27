class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int c = 0;
        int r = n - 1;

        while(c <= r){
            if(nums[c] == 0){
                swap(nums[l], nums[c]);
                l++;
                c++;
            }

            else if(nums[c] == 1){
                c++;
            }

            else{
                swap(nums[r], nums[c]);
                r--;
            }
        }
    }
};