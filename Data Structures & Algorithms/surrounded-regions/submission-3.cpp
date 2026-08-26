class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int dr[] = {0,0,-1,1};
        int dc[] = {1,-1,0,0};
        queue<pair<int,int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        board[i][j] = '#';
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

                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && board[nr][nc] == 'O'){
                    board[nr][nc] = '#';
                    q.push({nr,nc});
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
