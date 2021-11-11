class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN;
    priority_queue<pair<int, int>> pq;  // (y - x, x) max-heap

    for (const auto& p : points) {
      const int x = p[0];
      const int y = p[1];
      while (!pq.empty() && x - pq.top().second > k)
        pq.pop();
      if (!pq.empty())
        ans = max(ans, x + y + pq.top().first);
      pq.emplace(y - x, x);
    }

    return ans;
  }
};
