class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxWt = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            if(weights[i] > maxWt){
                maxWt = weights[i];
            }
        }
        int ans = 0;
        int r = sum;
        int l = maxWt;
        while(l <= r){
            int mid = (l+r)/2;
            int day = 1;
            int totalWeight = 0;
            for(int i = 0; i < weights.size(); i++){
                if(totalWeight + weights[i] > mid){
                    day++;
                    totalWeight = 0;
                }
                totalWeight += weights[i];
            }
            if(day <= days){
                ans = mid;
                r = mid - 1;
            } 
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};