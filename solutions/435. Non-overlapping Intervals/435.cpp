class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty())
      return 0;

    ranges::sort(intervals,
                 [](const auto& a, const auto& b) { return a[1] < b[1]; });

    int ans = 0;
    int currentEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i)
      if (intervals[i][0] >= currentEnd)
        currentEnd = intervals[i][1];
      else
        ++ans;

    return ans;
  }
};
