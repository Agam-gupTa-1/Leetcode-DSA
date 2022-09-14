// 51. N-Queens

Approach 1: O(n^3) and SC => O(N^3 ) + O(n)
  
class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int j = col, i = row;
        // upper diagonal
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q') return false;
            i--; j--;
        }
        i = row; j = col;
        // left 
        while(j>= 0)
        {
            if(board[i][j] == 'Q') return false;
            j--;
        }
        i = row; j = col; 
        // lower diagonal
        while(i < n && j >= 0)
        {
            if(board[i][j] == 'Q') return false;
            j--;
            i++;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return ;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(isSafe(i, col, board, n))
            {
                board[i][col] = 'Q';
                solve(col+1, board, ans, n);
                board[i][col] = '.';// backtracking step
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string row(n, '.');
        for(int i = 0; i < n; i++)
            board[i] = row;
        solve(0, board, ans, n);
        return ans;
    }
};

// Approach 2: with hash table TC: O(N2) and SC: O(N2) + o(n) + 2 O(2n) + o(n)

class Solution {
    // bool isSafe(int row, int col, vector<string> &board, int n)
    // {
    //     int j = col, i = row;
    //     // upper diagonal
    //     while(i >= 0 && j >= 0)
    //     {
    //         if(board[i][j] == 'Q') return false;
    //         i--; j--;
    //     }
    //     i = row; j = col;
    //     // left 
    //     while(j>= 0)
    //     {
    //         if(board[i][j] == 'Q') return false;
    //         j--;
    //     }
    //     i = row; j = col; 
    //     // lower diagonal
    //     while(i < n && j >= 0)
    //     {
    //         if(board[i][j] == 'Q') return false;
    //         j--;
    //         i++;
    //     }
    //     return true;
    // }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<bool> &left, vector<bool> &upperD, vector<bool> &lowerD)
    {
        if(col == n)
        {
            ans.push_back(board);
            return ;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!left[i] && !upperD[n-1+(col-i)] && !lowerD[col+i])
            {
                board[i][col] = 'Q';
                left[i] = true; upperD[n-1+(col-i)] = true; lowerD[col+i] = true;
                solve(col+1, board, ans, n, left, upperD, lowerD);
                board[i][col] = '.';   // backtracking step
                left[i] = false; upperD[n-1+(col-i)] = false; lowerD[col+i] = false; // backtracking step
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string row(n, '.');
        for(int i = 0; i < n; i++)
            board[i] = row;
        
        vector<bool> left(n, false), upperD(2*n-1, false), lowerD(2*n-1, false);
        
        solve(0, board, ans, n, left, upperD, lowerD);
        return ans;
    }
};
