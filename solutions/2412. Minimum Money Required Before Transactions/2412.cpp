class Solution {
 public:
  long long minimumMoney(vector<vector<int>>& transactions) {
    long long ans = 0;
    long long losses = 0;

    // Before picking the final transaction, perform any transaction that raises
    // the required money.
    for (const vector<int>& t : transactions) {
      const int cost = t[0];
      const int cashback = t[1];
      losses += max(0, cost - cashback);
    }

    // Now, pick a transaction to be the final one.
    for (const vector<int>& t : transactions) {
      const int cost = t[0];
      const int cashback = t[1];
      if (cost > cashback)
        // The losses except this transaction: losses - (cost - cashback), so
        // add the cost of this transaction = losses - (cost - cashback) + cost.
        ans = max(ans, losses + cashback);
      else
        // The losses except this transaction: losses, so add the cost of this
        // transaction = losses + cost.
        ans = max(ans, losses + cost);
    }

    return ans;
  }
};
