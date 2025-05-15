class Solution {
 public:
  long long maximumBooks(vector<int>& books) {
    // dp[i] := the maximum number of books we can take from books[0..i] with
    // taking all of books[i]
    vector<long> dp(books.size());
    stack<int> stack;  // the possible indices we can reach

    for (int i = 0; i < books.size(); ++i) {
      // We may take all of books[j], where books[j] < books[i] - (i - j).
      while (!stack.empty() &&
             books[stack.top()] >= books[i] - (i - stack.top()))
        stack.pop();
      // We can now take books[j + 1..i].
      const int j = stack.empty() ? -1 : stack.top();
      const int lastTook = books[i] - (i - j) + 1;
      if (lastTook > 1)
        // books[i] + (books[i] - 1) + ... + (books[i] - (i - j) + 1)
        dp[i] = static_cast<long>(books[i] + lastTook) * (i - j) / 2;
      else
        // 1 + 2 + ... + books[i]
        dp[i] = static_cast<long>(books[i]) * (books[i] + 1) / 2;
      if (j >= 0)
        dp[i] += dp[j];
      stack.push(i);
    }

    return ranges::max(dp);
  }
};
