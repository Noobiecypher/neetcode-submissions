class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = 0;
        int k = 0;
        for(int i = 0; i < n; i++){
            while(nums[j] != val && j < i){
                j++;
            }
            if(nums[i] != val){
                swap(nums[i], nums[j]);
                k++;
            }
        }
        return k;
    }
};