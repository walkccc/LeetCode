class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN;
    deque<pair<int, int>> maxQ;  // (y - x, x) max queue

    for (const vector<int>& point : points) {
      const int x = point[0];
      const int y = point[1];
      // Remove the invalid points, xj - xi > k.
      while (!maxQ.empty() && x - maxQ.front().second > k)
        maxQ.pop_front();
      if (!maxQ.empty())
        ans = max(ans, x + y + maxQ.front().first);
      // Remove the points that contribute less value and have a bigger x.
      while (!maxQ.empty() && y - x >= maxQ.back().first)
        maxQ.pop_back();
      maxQ.emplace_back(y - x, x);
    }

    return ans;
  }
};
