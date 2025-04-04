class Solution {
 public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    int ans = 0;
    int mx = -1;
    int secondMax = -1;

    ranges::sort(intervals, ranges::less{}, [](const vector<int>& interval) {
      const int start = interval[0];
      const int end = interval[1];
      return pair<int, int>{end, -start};
    });

    for (const vector<int>& interval : intervals) {
      const int start = interval[0];
      const int end = interval[1];
      // The maximum and the second maximum still satisfy.
      if (mx >= start && secondMax >= start)
        continue;
      if (mx >= start) {
        // The maximum still satisfy.
        secondMax = mx;
        mx = end;  // Add `end` to the set.
        ans += 1;
      } else {
        // The maximum and the second maximum can't satisfy.
        mx = end;             // Add `end` to the set.
        secondMax = end - 1;  // Add `end - 1` to the set.
        ans += 2;
      }
    }

    return ans;
  }
};
