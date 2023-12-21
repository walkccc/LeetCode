class Solution {
  long[] minimumRelativeLosses(int[] prices, int[][] queries) {
    final int n = prices.length;
    long[] ans = new long[queries.length];
    long[] prefix = new long[prices.length + 1];

    Arrays.sort(prices);

    for (int i = 0; i < prices.length; ++i)
      prefix[i + 1] = prefix[i] + prices[i];

    for (int i = 0; i < queries.length; ++i) {
      final int k = queries[i][0];
      final int m = queries[i][1];
      final int countFront = getCountFront(k, m, prices, prefix);
      final int countBack = m - countFront;
      ans[i] = getRelativeLoss(countFront, countBack, k, prefix);
    }

    return ans;
  }

  // Returns the `countFront` for query (k, m) s.t. picking the first
  // `countFront` and the last `m - countFront` chocolates is optimal.
  //
  // Define loss[i] := the relative loss of picking `prices[i]`.
  // 1. For prices[i] <= k, Bob pays prices[i] while Alice pays 0.
  //    Thus, loss[i] = prices[i] - 0 = prices[i].
  // 2. For prices[i] > k, Bob pays k while Alice pays prices[i] - k.
  //    Thus, loss[i] = k - (prices[i] - k) = 2 * k - prices[i].
  // By observation, we deduce that it is always better to pick from the front
  // or the back since loss[i] is increasing for 1. and is decreasing for 2.
  //
  // Assume that picking `left` chocolates from the left and `right = m - left`
  // chocolates from the right is optimal. Therefore, we are selecting
  // chocolates from `prices[0..left - 1]` and `prices[n - right..n - 1]`.
  //
  // To determine the optimal `left` in each iteration, we simply compare
  // `loss[left]` with `loss[n - right]`; if `loss[left] < loss[n - right]`,
  // it's worth increasing `left`.
  private int getCountFront(int k, int m, int[] prices, long[] prefix) {
    final int n = prices.length;
    final int countNoGreaterThanK = firstGreater(prices, k);
    int l = 0;
    int r = Math.min(countNoGreaterThanK, m);

    while (l < r) {
      final int mid = (l + r) / 2;
      final int right = m - mid;
      // Picking prices[mid] is better than picking prices[n - right].
      if (prices[mid] < 2L * k - prices[n - right])
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }

  private int firstGreater(int[] A, int val) {
    final int i = Arrays.binarySearch(A, val + 1);
    return i < 0 ? -i - 1 : i;
  }

  // Returns the relative loss of picking `countFront` and `countBack`
  // chocolates.
  private long getRelativeLoss(int countFront, int countBack, int k, long[] prefix) {
    final int n = prefix.length - 1;
    final long lossFront = prefix[countFront];
    final long lossBack = 2L * k * countBack - (prefix[n] - prefix[n - countBack]);
    return lossFront + lossBack;
  }
}
