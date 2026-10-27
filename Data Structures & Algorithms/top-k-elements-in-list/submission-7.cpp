class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }


        priority_queue<pair<int,int>> pq;
        for(auto p : freq){
            pq.push({p.second, p.first});
        }

        int i = 1;
        vector<int> ans(k,0);
        while(!pq.empty() && i <= k){
            ans[i - 1] = pq.top().second;
            pq.pop();
            i++;
        }
        return ans;
    }
};
