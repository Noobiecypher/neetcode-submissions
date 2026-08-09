class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n = nums.size();
      unordered_set<int> seq(nums.begin(), nums.end());
      int maxCount = 0;
      for(int i = 0; i < n; i++){
        if(!seq.count(nums[i] - 1)){
          int x = nums[i];
          int count = 1;
          while(seq.count(x+1)){
            count++;
            x++;
          }
          maxCount = max(maxCount,count);
        }
      }
      return maxCount;
    }
};
