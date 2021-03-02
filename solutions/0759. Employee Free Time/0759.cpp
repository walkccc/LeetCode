class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    if (schedule.size() <= 1)
      return {};

    vector<Interval> ans;
    vector<Interval> intervals;

    for (const auto& workingTimes : schedule)
      for (const Interval& interval : workingTimes)
        intervals.push_back(interval);

    sort(begin(intervals), end(intervals),
         [](const auto& a, const auto& b) { return a.start < b.start; });

    int prevEnd = intervals[0].end;

    for (const Interval& interval : intervals) {
      if (interval.start > prevEnd)
        ans.push_back({prevEnd, interval.start});
      prevEnd = max(prevEnd, interval.end);
    }

    return ans;
  }
};
