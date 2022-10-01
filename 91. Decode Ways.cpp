// 91. Decode Ways

// Partition DP 
Approach --> jitne digits ek sath include kr skte hai unko krte jao


class Solution {
    int solve(int i, int &n, string &s, vector<int> &dp)
    {
        if(i == n)
            return 1;
        if(dp[i] != -1) return dp[i];
        int ch = 0;
        int ways = 0;
        for(int j = i; j < n; j++)
        {
            ch = ch*10 + (s[j]-'0');
            if(ch == 0) return 0;
            if(ch > 26 ) break;
            ways += solve(j+1, n, s, dp);
        }
        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }
};
