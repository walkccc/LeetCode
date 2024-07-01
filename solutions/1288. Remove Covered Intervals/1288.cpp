class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // If the two intervals have the same `start`, put the one with a larger
    // `end` first.
    ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    int ans = 0;
    int prevEnd = 0;

    for (const vector<int>& interval : intervals)
      // Current interval is not covered by the previous one.
      if (prevEnd < interval[1]) {
        ++ans;
        prevEnd = interval[1];
      }

    return ans;
  }
};
