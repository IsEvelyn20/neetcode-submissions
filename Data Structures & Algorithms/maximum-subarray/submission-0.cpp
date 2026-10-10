class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int min_pre = 0, pre_sum = 0; 
        int ans = INT_MIN;
        for(int i = 0; i < n; i ++) {
            pre_sum += nums[i];
            ans = max(ans, pre_sum - min_pre);
            min_pre = min(min_pre, pre_sum);
        }
        return ans;
    }
};
