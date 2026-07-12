class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> sh;
        unordered_map<int,int> st;
        if(s.size() != t.size())return false;
        for(int i = 0; i < s.size(); i++){
            sh[s[i]]++;
            st[t[i]]++;
        }
        if(sh == st) return true;
        return false;
    }
};
