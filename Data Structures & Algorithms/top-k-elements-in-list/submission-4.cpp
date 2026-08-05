class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        vector<vector<int>> hm(n+1);
        for(auto p : freq){
            hm[p.second].push_back(p.first);
        }
        vector<int> ans;
        for(int i = n; i>= 1; i--){
            for(auto x : hm[i]){
                ans.push_back(x);
            }
            if(ans.size() == k){
                return ans;
            }
        }
    }
};
