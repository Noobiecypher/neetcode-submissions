class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxVol = 0;
        while(l < r){
            int h = min(heights[l], heights[r]);
            int vol = h * (r-l);
            maxVol = max(vol,maxVol);
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxVol;
    }
};
