class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        if(s.size() == 0) return 0;
        unordered_set<char> st;
        int maxLen = 0;
        for(int r = 0; r < s.size(); r++){
            while(st.find(s[r]) != st.end() && l <= r){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            int len = r - l+1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
