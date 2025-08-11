class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<Interval> ans;
    vector<Interval> intervals;

    for (const vector<Interval>& s : schedule)
      intervals.insert(intervals.end(), s.begin(), s.end());

    ranges::sort(intervals, ranges::less{},
                 [](const Interval& interval) { return interval.start; });

    int prevEnd = intervals[0].end;

    for (const auto& [start, end] : intervals) {
      if (start > prevEnd)
        ans.emplace_back(prevEnd, start);
      prevEnd = max(prevEnd, end);
    }

    return ans;
  }
};
