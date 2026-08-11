class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int r = n - 1;
        int l = 0;
        while (l <= r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};