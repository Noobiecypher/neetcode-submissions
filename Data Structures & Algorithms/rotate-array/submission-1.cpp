class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        k = k % n;
        int r = nums.size() - 1;
        int l = k;
        int start = 0;
        int end = k - 1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};