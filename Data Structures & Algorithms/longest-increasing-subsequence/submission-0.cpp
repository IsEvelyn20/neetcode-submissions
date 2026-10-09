class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) {
            return 0;
        }
        int ans = 1;
        vector<int>dp(n, 0);

        for(int i = 0; i < n; i ++) {
            dp[i] = 1;
            for(int j = 0; j < i; j ++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if(dp[i] > ans) ans = dp[i];
            }
        }
        return ans;
    }
};

//dp[i]目前到下标i为止，以i结尾的最长的上升子序列。
//dp[j]以j结尾的最长上升子序列，如果nums[j]<nums[i]，就看dp[i]有没有比dp[j]大。如果不大，就是dp[j] + 1。