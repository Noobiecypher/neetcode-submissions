class NumMatrix {
public:
vector<vector<int>> prefixMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefixMatrix.resize(rows + 1, vector<int>(cols+1,0));
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                prefixMatrix[i][j] = matrix[i-1][j-1] + prefixMatrix[i-1][j] 
                + prefixMatrix[i][j-1] 
                - prefixMatrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        return prefixMatrix[row2][col2] + prefixMatrix[row1-1][col1 -1] - prefixMatrix[row2][col1-1] - prefixMatrix[row1-1][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */