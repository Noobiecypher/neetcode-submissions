class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        if(strs.empty()){
            ans.push_back({""});
            return ans;
        }
        for(int i = 0; i < strs.size(); i++){
            vector<int> freq(26,0);
            int n = strs[i].size();
            for(int j = 0; j < n; j++){
                freq[strs[i][j] - 'a']++;
            }
            mp[freq].push_back(strs[i]);
        }
        
        for(auto [x,y] : mp){
            ans.push_back(y);
        }
        return ans;
    }
};
