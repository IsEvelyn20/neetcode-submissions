class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(int num : nums) {
            int tmp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};
