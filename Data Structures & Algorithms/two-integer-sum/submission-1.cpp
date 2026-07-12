class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comps;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(comps.find(complement) != comps.end()){
                return {comps[complement], i};
            }
            comps[nums[i]] = i;
        }
        return {};
    }
};
