class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int dr[] = {0,0,-1,1};
        int dc[] = {1,-1,0,0};
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        queue<pair<int,int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && !vis[nr][nc] && board[nr][nc] == 'O'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
