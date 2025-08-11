class Solution {
 public:
  int minimumCoins(vector<int>& prices) {
    const int n = prices.size();
    int ans = 0;
    using P = pair<int, int>;
    // Stores (dp[i], i), where dp[i] := the minimum number of coins to acquire
    // fruits[i:] (0-indexed).
    priority_queue<P, vector<P>, greater<>> minHeap;
    minHeap.emplace(0, n);

    for (int i = n - 1; i >= 0; --i) {
      while (!minHeap.empty() && minHeap.top().second > (i + 1) * 2)
        minHeap.pop();
      ans = prices[i] + minHeap.top().first;
      minHeap.emplace(ans, i);
    }

    return ans;
  }
};
