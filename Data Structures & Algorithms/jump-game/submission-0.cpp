class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        int maxReach = 0;
        for(int i = 0; i < n; i++){
            if(i <= maxReach){
                int reach = i + nums[i];
                maxReach = max(maxReach, reach);
                if(maxReach >= n - 1) return true;   
            }
        }
        return false;
    }
};
