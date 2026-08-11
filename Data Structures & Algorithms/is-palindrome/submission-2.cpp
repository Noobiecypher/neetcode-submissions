class Solution {
public:
    bool isPalindrome(string s) {
        string use;
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                use += s[i];
            }
        }

        int l = 0;
        int r = use.size() - 1;
        while(l <= r){
            if(toupper(use[l]) != toupper(use[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
