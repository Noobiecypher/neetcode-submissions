class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(string s : strs){
            vector<int> freq(26,0);
            string key;
            for(char c : s){
                freq[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                key += to_string(freq[i])+"#";
            }
            mp[key].push_back(s);
        }
        for(auto& [key, group] : mp){
            ans.push_back(group);
        }
        return ans;
    }
};
