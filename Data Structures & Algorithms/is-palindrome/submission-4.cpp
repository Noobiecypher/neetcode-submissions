class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size() - 1;
        while(l <= r){
            while(l <= r && (s[l] < '0' || (s[l] > '9' && s[l] < 'A') || (s[l] > 'Z' && s[l] < 'a') || s[l] > 'z')){
                l++;
            }
            while(l <= r && (s[r] < '0' || (s[r] > '9' && s[r] < 'A') || (s[r] > 'Z' && s[r] < 'a') || s[r] > 'z')){
                r--;
            }
            if( l > r ) break;

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
