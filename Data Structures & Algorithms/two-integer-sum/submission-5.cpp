class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            int pusher = target - nums[i];
            auto it = mp.find(pusher);
            if(it != mp.end()){
                return{it -> second, i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};
