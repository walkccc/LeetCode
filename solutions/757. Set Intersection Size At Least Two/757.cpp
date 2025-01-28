class Solution {
 public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    int ans = 0;
    int mx = -1;
    int secondMax = -1;

    ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
      return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
    });

    for (const vector<int>& interval : intervals) {
      const int a = interval[0];
      const int b = interval[1];
      // The maximum and the second maximum still satisfy.
      if (mx >= a && secondMax >= a)
        continue;
      if (mx >= a) {  // The maximum still satisfy.
        secondMax = mx;
        mx = b;  // Add b to the set S.
        ans += 1;
      } else {              // The maximum and the second maximum can't satisfy.
        mx = b;             // Add b to the set S.
        secondMax = b - 1;  // Add b - 1 to the set S.
        ans += 2;
      }
    }

    return ans;
  }
};
