class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
            if(mp.size() > 2){
                for(auto it = mp.begin(); it != mp.end(); ){
                    it -> second--;
                    if(it -> second == 0){
                        it = mp.erase(it);
                    }
                    else{
                        it++;
                    }
                }
            }
        }
        vector<int> ans;
        for(auto p : mp){
            int candidate = p.first;
            int count = 0;

            for(int x : nums){
                if(candidate == x){
                    count++;
                }
            }
            if(count > nums.size()/3){
                ans.push_back(candidate);
            }
        }
        return ans;
    }
};