class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = 1, curMax = 1;
        int res = nums[0];
        for(int num : nums) {
            int tmp = num * curMax;
            curMax = max(max(curMin * num, tmp), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};
