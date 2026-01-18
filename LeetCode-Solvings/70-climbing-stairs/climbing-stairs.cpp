class Solution {
public:
    int climbStairsByMemoizationDP(int n, vector<int>& dp) {   //O(2^n) - Exponential Time Complexity
        if(n == 0 || n == 1) {
            return dp[n] = 1;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        dp[n] = climbStairsByMemoizationDP(n-1, dp) + climbStairsByMemoizationDP(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {    //O(n)
        vector<int> dp(n+1, -1);
        return climbStairsByMemoizationDP(n, dp);
    }
};