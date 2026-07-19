class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       vector<int> coster(n);
       coster[0] = cost[0];
       coster[1] = cost[1];
       for(int i = 2; i < n; i++){
        coster[i] = cost[i] + min(coster[i-1], coster[i - 2]);
       }
       return min(coster[n - 1], coster[n - 2]);
    }
};
