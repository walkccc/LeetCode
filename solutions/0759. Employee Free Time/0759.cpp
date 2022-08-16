class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<Interval> ans;
    vector<Interval> intervals;

    for (const auto& s : schedule)
      intervals.insert(end(intervals), begin(s), end(s));

    sort(begin(intervals), end(intervals),
         [](const auto& a, const auto& b) { return a.start < b.start; });

    int prevEnd = intervals[0].end;

    for (const auto& [start, end] : intervals) {
      if (start > prevEnd)
        ans.emplace_back(prevEnd, start);
      prevEnd = max(prevEnd, end);
    }

    return ans;
  }
};
