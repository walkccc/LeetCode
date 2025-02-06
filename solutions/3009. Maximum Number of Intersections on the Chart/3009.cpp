class Solution {
 public:
  int maxIntersectionCount(vector<int>& y) {
    const int n = y.size();
    int ans = 0;
    int intersectionCount = 0;
    map<int, int> line;

    for (int i = 1; i < n; ++i) {
      const int start = 2 * y[i - 1];
      const int end = 2 * y[i] + (i == n - 1 ? 0 : y[i] > y[i - 1] ? -1 : 1);
      ++line[min(start, end)];
      --line[max(start, end) + 1];
    }

    for (const auto& [_, count] : line) {
      intersectionCount += count;
      ans = max(ans, intersectionCount);
    }

    return ans;
  }
};
