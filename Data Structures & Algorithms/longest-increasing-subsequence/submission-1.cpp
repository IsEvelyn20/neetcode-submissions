class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size(), 0);
        int res = 0;
        for(int num : nums) {
            int i = 0;
            int j = res;
            while(i < j) {
                int mid = (i + j) / 2;
                if(tails[mid] < num) {
                    i = mid + 1;
                } else {
                    j = mid;
                }
            }
            tails[i] = num;
            if(j == res) res += 1;
        }
        return res;
    }
};

//tails表示长度为i的末尾元素最小值tails[i]，然后遍历这个nums数组，如果比tails数组里某个位置更小，那就更新，因为不影响后面数组，并且给之后新出现的num更大的可能性继续递增。不然如果一个值已经足够大，那后面的数字比他大的可能性很小。
// 如何知道更新的位置，就用二分去更新。