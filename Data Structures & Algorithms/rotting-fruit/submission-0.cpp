class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int fresh = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({{i,j},0});
            }
        }
        int minutes = 0;
        int dr[] = {0,0,1,-1};
        int dc[] = {1, -1, 0, 0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int level = q.front().second;
            q.pop();
            minutes = max(level, minutes);
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                    fresh--;
                    grid[nr][nc] = 2;
                    q.push({{nr,nc}, level + 1});
                }
            }
        }
        if(fresh > 0) return -1;
        else return minutes;
    }
};
