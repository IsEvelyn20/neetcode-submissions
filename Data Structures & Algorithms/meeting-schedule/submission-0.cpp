/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u.start < v.start;
        });
        int n = intervals.size();
        int right = intervals[0].end;
        for(int i = 1; i < n; i ++) {
            if(intervals[i].start < right) {
                return false;
            } else {
                right = intervals[i].end;
            }
        }
        return true;
    }
};
