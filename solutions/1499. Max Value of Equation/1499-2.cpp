class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN;
    deque<pair<int, int>> q;  // (y - x, x) max queue

    for (const auto& p : points) {
      const int x = p[0];
      const int y = p[1];
      // remove invalid points, xj - xi > k
      while (!q.empty() && x - q.front().second > k)
        q.pop_front();
      if (!q.empty())
        ans = max(ans, x + y + q.front().first);
      // remove points that contribute less value and have bigger x
      while (!q.empty() && y - x >= q.back().first)
        q.pop_back();
      q.emplace_back(y - x, x);
    }

    return ans;
  }
};
