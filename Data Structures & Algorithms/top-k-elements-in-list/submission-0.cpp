class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }

        vector<vector<int>> bsort(nums.size() + 1);
        for(auto& [nums, count] : freq){
            bsort[count].push_back(nums);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 1 && ans.size() < k; i--){
            for(int num : bsort[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};
