class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> straight(n,0);
        vector<int> rev(n,0);
        

        straight[0] = 1;
        rev[n-1] = 1;
        
        for(int i = 1; i < n; i++){
            straight[i] = straight[i-1] * nums[i-1];
            rev[n-i-1] = rev[n-i] * nums[n-i];
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = straight[i] * rev[i];
        }
        return ans;
    }
};
