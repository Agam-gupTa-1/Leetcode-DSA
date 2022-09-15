// 37. Sudoku Solver


A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
  
  // code
  
  class Solution {
    bool solve(vector<vector<char>>& board, int n, int m)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(isValid(board, i, j, c))
                        {
                            board[i][j] = c;
                            if(solve(board, n, m) == true)
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0; i < 9; i++)
        {
            // row
            if(board[row][i] == c) return false;
            // col
            if(board[i][col] == c) return false;
            
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        solve(board, n, m);
    }
};
