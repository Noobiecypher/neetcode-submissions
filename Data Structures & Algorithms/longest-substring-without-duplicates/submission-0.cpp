class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxi = 0;
        unordered_set<int> us;
        while(l < n && r < n){
            int length = 0;
            if(us.find(s[r]) == us.end()){
                us.insert(s[r]);
                length = r - l + 1;
                r++;
                maxi = max(length, maxi);
            }
            else{
                while(us.find(s[r]) != us.end() && l < r){
                    us.erase(s[l]);
                    l++;
                }
            }
        }
        return maxi;
    }
};
