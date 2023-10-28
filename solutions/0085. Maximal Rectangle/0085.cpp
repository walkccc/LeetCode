class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty())
      return 0;

    int ans = 0;
    vector<int> hist(matrix[0].size());

    for (const vector<char>& row : matrix) {
      for (int i = 0; i < row.size(); ++i)
        hist[i] = row[i] == '0' ? 0 : hist[i] + 1;
      ans = max(ans, largestRectangleArea(hist));
    }

    return ans;
  }

 private:
  int largestRectangleArea(const vector<int>& heights) {
    int ans = 0;
    stack<int> stack;

    for (int i = 0; i <= heights.size(); ++i) {
      while (!stack.empty() &&
             (i == heights.size() || heights[stack.top()] > heights[i])) {
        const int h = heights[stack.top()];
        stack.pop();
        const int w = stack.empty() ? i : i - stack.top() - 1;
        ans = max(ans, h * w);
      }
      stack.push(i);
    }

    return ans;
  }
};
