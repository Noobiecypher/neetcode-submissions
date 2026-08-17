class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int max = INT_MIN;
        int sum = 0;
        for(auto it : nums){
            if(it > max) max = it;
            sum += it;
        }

        int l = max;
        int r = sum;
        int ans = 0;
        
        while(l <= r){
            int mid = (l+r)/2;
            int subs = 1;
            int tsum = 0;
            for(auto it : nums){
                if(tsum + it > mid){
                    subs++;
                    tsum = 0;
                }
                tsum += it;
            }
            if(subs > k){
                l = mid + 1;
            }
            else{
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};