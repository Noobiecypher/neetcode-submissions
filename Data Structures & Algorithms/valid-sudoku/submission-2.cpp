class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> grids[9];
        int r = board.size();
        int c = board[0].size();
        int grid = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                char c = board[i][j];
                if(c == '.')continue;
                if(rows[i].count(c)) return false;
                if(cols[j].count(c)) return false;
                int grid = (3 * (i/3)) + (j/3);
                if(grids[grid].count(c)) return false;

                rows[i].insert(c);
                cols[j].insert(c);
                grids[grid].insert(c);
            }
        }
        return true;
    }
};
