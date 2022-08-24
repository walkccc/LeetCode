class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    int ans = INT_MAX;
    unordered_map<int, unordered_set<int>> xToYs;

    for (const auto& p : points)
      xToYs[p[0]].insert(p[1]);

    for (int i = 1; i < points.size(); ++i)
      for (int j = 0; j < i; ++j) {
        const vector<int>& p = points[i];
        const vector<int>& q = points[j];
        if (p[0] == q[0] || p[1] == q[1])
          continue;
        if (xToYs[p[0]].count(q[1]) && xToYs[q[0]].count(p[1]))
          ans = min(ans, abs(p[0] - q[0]) * abs(p[1] - q[1]));
      }

    return ans == INT_MAX ? 0 : ans;
  }
};
