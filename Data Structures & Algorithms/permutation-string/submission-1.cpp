class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        unordered_map<char,int> mpt;
        if(s1.size() > s2.size()) return false;
        for(int i = 0; i < s1.size(); i++){
            mp[s1[i]]++;
        }
        int l = 0;
        for(int i = 0; i < s2.length(); i++){
            if(i - l + 1 > s1.size()){
                mpt[s2[l]]--;
                if (mpt[s2[l]] == 0) {
                    mpt.erase(s2[l]);
                }
                l++;
            }
            mpt[s2[i]]++;
            if(mpt == mp)return true;
        }
        return false;
    }
};
