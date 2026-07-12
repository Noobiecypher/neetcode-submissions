class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sh;
        unordered_map<char,int> st;
        if(s.size() != t.size())return false;
        for(int i = 0; i < s.size(); i++){
            sh[s[i]]++;
            st[t[i]]++;
        }
        if(sh == st) return true;
        return false;
    }
};
