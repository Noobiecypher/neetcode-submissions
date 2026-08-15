class Solution {
   public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int startIndex = -1;
        int minLen = INT_MAX;
        int hash[256] = {0};
        int cnt = 0;
        for (auto c : t) {
            hash[c]++;
        }
        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == t.size()) {
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }
                l++;
            }
            r++;
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};
