class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 0) return 1;
        int prev2 = 1;
        int prev = 1;
        int curi = 0;
        for(int i = 2; i <= n; i++){
            curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return curi;
    }
};
