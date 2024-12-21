class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    const int n = arr.size();
    // dp[i] := the maximum jumps starting from arr[i]
    vector<int> dp(n, 1);
    // a dcreasing stack that stores indices
    stack<int> stack;

    for (int i = 0; i <= n; ++i) {
      while (!stack.empty() && (i == n || arr[stack.top()] < arr[i])) {
        vector<int> indices{stack.top()};
        stack.pop();
        while (!stack.empty() && arr[stack.top()] == arr[indices[0]])
          indices.push_back(stack.top()), stack.pop();
        for (const int j : indices) {
          if (i < n && i - j <= d)
            // Can jump from i to j.
            dp[i] = max(dp[i], dp[j] + 1);
          if (!stack.empty() && j - stack.top() <= d)
            // Can jump from stack[-1] to j.
            dp[stack.top()] = max(dp[stack.top()], dp[j] + 1);
        }
      }
      stack.push(i);
    }

    return ranges::max(dp);
  }
};
