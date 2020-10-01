class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    if (schedule.size() <= 1) return {};

    vector<Interval> ans;
    vector<Interval> intervals;

    for (const vector<Interval>& workingTimes : schedule)
      for (const Interval& interval : workingTimes)
        intervals.push_back(interval);

    sort(begin(intervals), end(intervals),
         [](const auto& a, const auto& b) { return a.start < b.start; });

    int currentEnd = intervals[0].end;

    for (const Interval& interval : intervals)
      if (interval.start > currentEnd) {
        ans.push_back({currentEnd, interval.start});
        currentEnd = interval.end;
      } else {
        currentEnd = max(currentEnd, interval.end);
      }

    return ans;
  }
};