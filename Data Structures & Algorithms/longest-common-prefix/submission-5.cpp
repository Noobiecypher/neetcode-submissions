class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string tester = strs[i];
            for(int j = 0; j < s.size(); j++){
                if(s[j] != tester[j]) s = s.substr(0,j);
            }
        }
        return s;
    }
};