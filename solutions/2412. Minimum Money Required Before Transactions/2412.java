class Solution {
  public long minimumMoney(int[][] transactions) {
    long ans = 0;
    long losses = 0;

    // Before picking the final transaction, perform any transaction that raises
    // the required money.
    for (int[] t : transactions) {
      final int cost = t[0];
      final int cashback = t[1];
      losses += Math.max(0, cost - cashback);
    }

    // Now, pick a transaction to be the final one.
    for (int[] t : transactions) {
      final int cost = t[0];
      final int cashback = t[1];
      if (cost > cashback)
        // The losses except this transaction: losses - (cost - cashback), so
        // add the cost of this transaction = losses - (cost - cashback) + cost.
        ans = Math.max(ans, losses + cashback);
      else
        // The losses except this transaction: losses, so add the cost of this
        // transaction = losses + cost.
        ans = Math.max(ans, losses + cost);
    }

    return ans;
  }
}
