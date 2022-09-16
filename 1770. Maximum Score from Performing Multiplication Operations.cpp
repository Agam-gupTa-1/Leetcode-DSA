// 1770. Maximum Score from Performing Multiplication Operations
You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations

// Approach
Greedy solution will not work here, as in greedy we explore only one path (at each index we picked up only maximum value which may result in lesser score later, uncertainity of data), so we have to explore all possibilites at each index --> recursion

// Solution 1 using 3 changing parameters
// TC = O(m^3) SC = O(m*m*n)
class Solution {
    int solve(int i, vector<int>& nums, vector<int>& mul, int m, int s, int e, vector<vector<vector<int>>> &dp)
    {
        if(i == m)
            return 0;
        if(dp[i][s][e] != -1) return dp[i][s][e];
        int left = mul[i]*nums[s] + solve(i+1, nums, mul, m, s+1, e, dp);
        int right = mul[i]*nums[e] + solve(i+1, nums, mul, m, s, e-1, dp);
        
        return dp[i][s][e] = max(left, right);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size(), n = nums.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (m, vector<int>(n, -1)));
        return solve(0, nums, multipliers, m, 0, n-1, dp);
    }
};

// Solution 2
We can optimize to 2 params which is dp(l, i), time complexity = O(m^2) , we can compute params r base on l and i:
Where:
l, r is the index of the left side and the right side corresponding.
i is the number of elements that we picked.
leftPicked: is the number of elements picked on the left side, leftPicked = l.
rightPicked: is the number of elements picked on the right side, rightPicked = i - leftPicked = i - l.
Finally: r = n - rightPicked - 1 = n - (i-l) - 1.
Complexity

Time: O(2 * m^2), where m <= 10^3
Space: O(m^2)
  
// code
 class Solution {
    int solve(int i, vector<int>& nums, vector<int>& mul, int m, int n, int l, vector<vector<int>> &dp)
    {
        if(i == m)
            return 0;
        if(dp[i][l] != INT_MIN) return dp[i][l];
        int rpicked = i - l;
        int r = n-1-rpicked;
        int left = mul[i]*nums[l] + solve(i+1, nums, mul, m, n, l+1, dp);
        int right = mul[i]*nums[r] + solve(i+1, nums, mul, m, n, l, dp);
        
        return dp[i][l] = max(left, right);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size(), n = nums.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        return solve(0, nums, multipliers, m, n, 0, dp);
    }
};
