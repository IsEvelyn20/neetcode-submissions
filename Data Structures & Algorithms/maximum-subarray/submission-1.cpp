class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int pre_sum = 0, min_sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            pre_sum += nums[i];
            ans = max(ans, pre_sum - min_sum);
            min_sum = min(pre_sum, min_sum);
        }
        return ans;
    }
};
