class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; 
        int j = heights.size() - 1;
        int maxvol = 0;
        while(i < j){
            int mini = min(heights[i], heights[j]);
            int vol = (j - i)*mini;
            maxvol = max(maxvol, vol);
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxvol;
    }
};
