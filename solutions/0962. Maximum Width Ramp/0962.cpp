class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    int ans = 0;
    stack<int> stack;

    for (int i = 0; i < A.size(); ++i)
      if (stack.empty() || A[i] < A[stack.top()])
        stack.push(i);

    for (int i = A.size() - 1; i > ans; --i)
      while (!stack.empty() && A[i] >= A[stack.top()])
        ans = max(ans, i - stack.top()), stack.pop();

    return ans;
  }
};
