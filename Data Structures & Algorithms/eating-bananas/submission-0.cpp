class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int maxi = 0;
        for(int it : piles){
            if(it > maxi){
                maxi = it;
            }
        }
        int r = maxi;
        int ans = 0;
        while(l <= r){
            int mid = (l + r)/2;
            int sum = 0;
            for(int it : piles){
                int hours = ceil((double)it/mid);
                sum += hours;
            }
            if(sum > h) l = mid + 1;
            if(sum <= h){
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};
