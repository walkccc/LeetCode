class FenwickTree {
  public FenwickTree(int n) {
    vals = new int[n + 1];
  }

  public void update(int i, int val) {
    while (i < vals.length) {
      vals[i] = Math.max(vals[i], val);
      i += lowbit(i);
    }
  }

  public int get(int i) {
    int res = 0;
    while (i > 0) {
      res = Math.max(res, vals[i]);
      i -= lowbit(i);
    }
    return res;
  }

  private int[] vals;

  private static int lowbit(int i) {
    return i & -i;
  }
}

class Solution {
  // Same as 2907. Maximum Profitable Triplets With Increasing Prices I
  public int maxProfit(int[] prices, int[] profits) {
    final int maxPrice = Arrays.stream(prices).max().getAsInt();
    int ans = -1;
    FenwickTree maxProfitTree1 = new FenwickTree(maxPrice);
    FenwickTree maxProfitTree2 = new FenwickTree(maxPrice);

    for (int i = 0; i < prices.length; ++i) {
      final int price = prices[i];
      final int profit = profits[i];
      // max(profits[i])
      final int maxProfit1 = maxProfitTree1.get(price - 1);
      // max(proftis[i]) + max(profits[j])
      final int maxProfit2 = maxProfitTree2.get(price - 1);
      maxProfitTree1.update(price, profit);
      if (maxProfit1 > 0)
        maxProfitTree2.update(price, profit + maxProfit1);
      if (maxProfit2 > 0)
        ans = Math.max(ans, profit + maxProfit2);
    }

    return ans;
  }
}
