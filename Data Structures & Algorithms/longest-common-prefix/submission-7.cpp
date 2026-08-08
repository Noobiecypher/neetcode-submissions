class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string tester = strs[i];
            int j = 0;
            while(j < s.size() && j < tester.size() && s[j] == tester[j]){j++;}
            s = s.substr(0,j);
            if(s.empty()) return "";
        }
        return s;
    }
};