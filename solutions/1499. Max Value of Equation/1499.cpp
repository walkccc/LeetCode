class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN;
    deque<pair<int, int>> q;  // {y - x, x}

    for (const auto& point : points) {
      const int x = point[0];
      const int y = point[1];
      // remove invalid points (xj - xi > k)
      while (!q.empty() && x - q.front().second > k)
        q.pop_front();
      if (!q.empty())
        ans = max(ans, x + y + q.front().first);
      while (!q.empty() && y - x >= q.back().first)
        q.pop_back();
      q.push_back({y - x, x});
    }

    return ans;
  }
};
