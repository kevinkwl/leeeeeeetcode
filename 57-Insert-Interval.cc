/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i;
        for (i = 0; i < intervals.size() && intervals[i].end < newInterval.start; i++)
            res.push_back(intervals[i]);
        res.push_back(newInterval);
        bool merge = true;
        for (; i < intervals.size(); i++) {
            if (!merge) {
                res.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].start > res.back().end) {
                res.push_back(intervals[i]);
                merge = false;
            } else {
                if (intervals[i].start < res.back().start)
                    res.back().start = intervals[i].start;
                if (intervals[i].end > res.back().end)
                    res.back().end = intervals[i].end;
            }
        }
        return res;
    }
};

/** binary search to find the pos for new interval

        int lo = 0, hi = intervals.size();
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (intervals[mid].end < newInterval.start)
                lo = mid + 1;
            else
                hi = mid;
        }
 */
