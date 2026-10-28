class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(const auto& interval : intervals) {
            int left = interval[0], right = interval[1];
            if(res.back()[1] < left) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
    }
};
