class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN;
    priority_queue<pair<int, int>> maxHeap;  // (y - x, x)

    for (const vector<int>& p : points) {
      const int x = p[0];
      const int y = p[1];
      while (!maxHeap.empty() && x - maxHeap.top().second > k)
        maxHeap.pop();
      if (!maxHeap.empty())
        ans = max(ans, x + y + maxHeap.top().first);
      maxHeap.emplace(y - x, x);
    }

    return ans;
  }
};
