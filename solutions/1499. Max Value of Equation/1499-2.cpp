class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN;
    deque<pair<int, int>> dq;  // (y - x, x) max queue

    for (const vector<int>& p : points) {
      const int x = p[0];
      const int y = p[1];
      // Remove invalid points, xj - xi > k
      while (!dq.empty() && x - dq.front().second > k)
        dq.pop_front();
      if (!dq.empty())
        ans = max(ans, x + y + dq.front().first);
      // Remove points that contribute less value and have bigger x
      while (!dq.empty() && y - x >= dq.back().first)
        dq.pop_back();
      dq.emplace_back(y - x, x);
    }

    return ans;
  }
};
