class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[rows - 1][cols - 1])return false;
        int lr = 0;
        int rr = rows - 1;
        int ansr = 0;
        while(lr <= rr){
            int mid = (lr + rr)/2;
            if(matrix[mid][cols - 1] < target){
                lr = mid + 1;
            }
            else{
                ansr = mid;
                rr = mid - 1;
            }
        }

        int lc = 0;
        int rc = cols - 1;
        while(lc <= rc){
            int mid = (lc + rc)/2;
           if(matrix[ansr][mid] < target){
                lc = mid + 1;
            }
            else if(matrix[ansr][mid] > target){
                rc = mid - 1;
            }
            else return true;
        }
        return false;
    }
};
