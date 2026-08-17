class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        long long int l = 1;
        long long int r = x/2 + 1;
        long long ans = 1;
        while(l <= r){
            long long mid = (l+r)/2;
            long long mds = mid * mid;
            if(mds <= x){
                ans = mid;
                l = mid + 1;
            } 
            else if(mds > x) r = mid - 1;
            
        }
        return ans;
    }
};