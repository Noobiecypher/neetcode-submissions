class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() <= 1) return arr.size();
        int down = 1;
        int up = 1;
        int totalCount = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1] > arr[i]){
                down = up + 1;
                up = 1;
            }
            else if(arr[i-1] < arr[i]){
                up = down + 1;
                down = 1;
            }
            else{
                down = 1;
                up = 1;
            }
            totalCount = max(totalCount, max(up,down));
        }
        return totalCount;
    }
};