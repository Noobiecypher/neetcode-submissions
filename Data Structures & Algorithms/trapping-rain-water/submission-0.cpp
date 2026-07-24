class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int l = 0;
        int r = height.size() - 1;
        int leftM = height[0];
        int rightM = height[r];
        int res = 0;
        while(l < r){
            if(leftM < rightM){
                l++;
                leftM = max(leftM, height[l]);
                res += leftM - height[l];
            }

            else{
                r--;
                rightM = max(rightM, height[r]);
                res += rightM - height[r];
            }
        }
        return res;
    }
};
