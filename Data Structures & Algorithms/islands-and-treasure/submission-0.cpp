class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 2147483647){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
