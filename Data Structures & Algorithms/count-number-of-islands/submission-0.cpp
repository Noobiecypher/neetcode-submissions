class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(), 0));
        int count = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    vis[i][j] = 1;
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;

                        for(int k = 0; k < 4; k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k]; 
                            if(nr < grid.size() && nc < grid[0].size() && !vis[nr][nc] && grid[nr][nc] == '1'){
                                q.push({nr,nc});
                                vis[nr][nc] = 1;
                            }
                        }
                        q.pop();
                    } 
                }
            }
        }
        return count;
    }
};
