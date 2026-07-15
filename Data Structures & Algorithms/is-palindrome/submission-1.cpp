class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            if( l < r && ((s[l] < '0') || ((s[l] > '9') && (s[l] < 'A')) || ((s[l] > 'Z') && (s[l] < 'a')) || (s[l] > 'z'))){
                l++;
                continue;
            }
            if( l < r && ((s[r] < '0') || ((s[r] > '9') && (s[r] < 'A')) || ((s[r] > 'Z') && (s[r] < 'a')) || (s[r] > 'z'))){
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
