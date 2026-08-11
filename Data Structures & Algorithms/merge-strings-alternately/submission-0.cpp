class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int l = 0;
        int miner = min(word1.size(), word2.size());
        while(l < miner){
            s += word1[l];
            s += word2[l];
            l++;
        }

        if(miner < word1.size()){
            while( l < word1.size()){
                s += word1[l];
                l++;
            }
        }

        if(miner < word2.size()){
            while( l < word2.size()){
                s += word2[l];
                l++;
            }
        }
        return s;
    }
};