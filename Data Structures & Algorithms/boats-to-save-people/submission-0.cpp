class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int count = 0;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            while (l <= r && people[r] == limit) {
                count++;
                r--;
            }
            while(l <= r && people[l] + people[r] <= limit){
                count++;
                l++;
                r--;
            }

            while(l <= r && people[l] + people[r] > limit){
                count++;
                r--;
            }
        }
        return count;
    }
};