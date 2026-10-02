class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if(n <= 2) return n;
        dp.resize(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i --) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }

        return dp[0];
        
    }
};
