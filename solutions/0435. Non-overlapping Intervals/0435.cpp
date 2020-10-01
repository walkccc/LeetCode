class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int ans = 0;
    int currentEnd = INT_MIN;

    sort(begin(intervals), end(intervals),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });

    for (const vector<int>& interval : intervals)
      if (interval[0] >= currentEnd)
        currentEnd = interval[1];
      else
        ++ans;

    return ans;
  }
};