class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int maxcount = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                queue<pair<int,int>> q;
                if(grid[i][j] && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                    int count = 1;
                    while(!q.empty()){
                        auto [n,m] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int nr = n + dr[k];
                            int nc = m + dc[k];
                            if(nr >= 0 && nr < rows
                            && nc >= 0 && nc < cols &&
                            !vis[nr][nc] && grid[nr][nc] == 1){
                                count++;
                                q.push({nr,nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }   
                    maxcount = max(count,maxcount);
                }
            }
        }
        return maxcount;
    }
};
