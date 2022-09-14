// 52. N-Queens II
class Solution {
    void solve(int col, int &n, vector<vector<bool>> &board, int &cnt, vector<bool> &left, vector<bool> &upperD, vector<bool> &lowerD)
    {
        if(col == n)
        {
            cnt++;
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!left[i] && !upperD[n-1+(col-i)] && !lowerD[col+i])
            {
                board[i][col] = 1;
                left[i] = true; upperD[n-1+(col-i)] = true; lowerD[col+i] = true;
                solve(col+1, n, board, cnt, left, upperD, lowerD);
                // backtracking step
                board[i][col] = 0;
                left[i] = 0; upperD[n-1+(col-i)] = 0; lowerD[col+i] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<vector<bool>> board(n, vector<bool> (n, false));
        vector<bool> left(n, false), upperD(2*n-1, false), lowerD(2*n-1, false);
        solve(0, n, board, cnt, left, upperD, lowerD);
        return cnt;
    }
};
