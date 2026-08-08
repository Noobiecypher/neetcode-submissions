class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> hm(n+1);
        for(auto it : freq){
            hm[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = n; i >= 0; i--){
            for(auto iter : hm[i]){
                ans.push_back(iter);
            }
            if(ans.size() == k) return ans;
        }
    }
};
