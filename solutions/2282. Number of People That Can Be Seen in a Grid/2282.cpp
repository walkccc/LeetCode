class Solution {
 public:
  vector<vector<int>> seePeople(vector<vector<int>>& heights) {
    const int m = heights.size();
    const int n = heights[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      stack<int> stack;
      for (int j = 0; j < n; ++j) {
        bool hasEqualHeight = false;
        while (!stack.empty() && heights[i][stack.top()] <= heights[i][j]) {
          if (heights[i][stack.top()] == heights[i][j])
            // edge case: [4, 2, 1, 1, 3]
            hasEqualHeight = true;
          ++ans[i][stack.top()], stack.pop();
        }
        if (!stack.empty() && !hasEqualHeight)
          ++ans[i][stack.top()];
        stack.push(j);
      }
    }

    for (int j = 0; j < n; ++j) {
      stack<int> stack;
      for (int i = 0; i < m; ++i) {
        bool hasEqualHeight = false;
        while (!stack.empty() && heights[stack.top()][j] <= heights[i][j]) {
          if (heights[stack.top()][j] == heights[i][j])
            hasEqualHeight = true;
          ++ans[stack.top()][j], stack.pop();
        }
        if (!stack.empty() && !hasEqualHeight)
          ++ans[stack.top()][j];
        stack.push(i);
      }
    }

    return ans;
  }
};
