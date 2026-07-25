class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freqa(26,0);
        vector<int>freqb(26,0);
        for(int i = 0; i < s1.size(); i++){
            freqa[s1[i] - 'a']++;
        }
        int l = 0;
        int r = 0;
        while(r < s2.size()){
            freqb[s2[r] - 'a']++;
            if((r-l+1) > s1.size()){
                freqb[s2[l] - 'a']--;
                l++;
            }
            if(freqa == freqb) return true;
            r++;
        }
        return false;
    }
};
