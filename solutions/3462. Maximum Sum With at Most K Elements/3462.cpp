class Solution {
 public:
  long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    long ans = 0;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int i = 0; i < grid.size(); ++i) {
      ranges::sort(grid[i], greater<>());
      for (int j = 0; j < limits[i]; ++j) {
        minHeap.push(grid[i][j]);
        if (minHeap.size() == k + 1)
          minHeap.pop();
      }
    }

    while (!minHeap.empty())
      ans += minHeap.top(), minHeap.pop();

    return ans;
  }
};
