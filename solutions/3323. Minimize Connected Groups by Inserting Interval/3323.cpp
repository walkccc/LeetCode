class Solution {
 public:
  int minConnectedGroups(vector<vector<int>>& intervals, int k) {
    int mergedIntervals = 0;
    int maxMergedIntervals = 0;

    intervals = merge(intervals);

    int i = 0;
    for (const vector<int>& interval : intervals) {
      const int end = interval[1];
      while (i < intervals.size() && end + k >= intervals[i][0]) {
        ++mergedIntervals;
        ++i;
      }
      --mergedIntervals;  // Exclude intervals[i].
      maxMergedIntervals = max(maxMergedIntervals, mergedIntervals);
    }

    return intervals.size() - maxMergedIntervals;
  }

 private:
  // Same as 56. Merge Intervals
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    ranges::sort(intervals);
    for (const vector<int>& interval : intervals)
      if (res.empty() || res.back()[1] < interval[0])
        res.push_back(interval);
      else
        res.back()[1] = max(res.back()[1], interval[1]);
    return res;
  }
};
