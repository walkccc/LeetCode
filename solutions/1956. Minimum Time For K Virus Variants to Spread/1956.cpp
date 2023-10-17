class Solution {
 public:
  int minDayskVariants(vector<vector<int>>& points, int k) {
    constexpr int kMax = 100;
    int ans = INT_MAX;

    for (int a = 1; a <= kMax; ++a)
      for (int b = 1; b <= kMax; ++b) {
        // Store the k smallest distances of points that can reach (a, b).
        priority_queue<int> maxHeap;
        for (const vector<int>& point : points) {
          const int x = point[0];
          const int y = point[1];
          maxHeap.push(abs(x - a) + abs(y - b));
          if (maxHeap.size() > k)
            maxHeap.pop();
        }
        ans = min(ans, maxHeap.top());
      }

    return ans;
  }
};
