class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l <= r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                return isPalindrome(s.substr(l,r-l)) || isPalindrome(s.substr(l+1,r - l));
            }
        }
        return true;
    }
};