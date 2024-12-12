class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    const int n = heights.size();
    vector<int> ans(n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && heights[stack.top()] <= heights[i])
        ++ans[stack.top()], stack.pop();
      if (!stack.empty())
        ++ans[stack.top()];
      stack.push(i);
    }

    return ans;
  }
};
