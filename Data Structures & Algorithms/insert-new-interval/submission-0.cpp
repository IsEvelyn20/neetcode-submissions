class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> ans;
        bool placed = false;
        for(const auto& interval : intervals) {
            if(right < interval[0]) {
                if(!placed) {
                    ans.push_back({left,right});
                    placed = true;
                }
                ans.push_back(interval);
            } else if(left > interval[1]) {
                ans.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if(!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
