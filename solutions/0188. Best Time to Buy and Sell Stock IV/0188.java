class Solution {
  public int maxProfit(int k, int[] prices) {
    if (k >= prices.length / 2) {
      int sell = 0;
      int hold = Integer.MIN_VALUE;

      for (final int price : prices) {
        sell = Math.max(sell, hold + price);
        hold = Math.max(hold, sell - price);
      }

      return sell;
    }

    int[] sell = new int[k + 1];
    int[] hold = new int[k + 1];
    Arrays.fill(hold, Integer.MIN_VALUE);

    for (final int price : prices)
      for (int i = k; i > 0; --i) {
        sell[i] = Math.max(sell[i], hold[i] + price);
        hold[i] = Math.max(hold[i], sell[i - 1] - price);
      }

    return sell[k];
  }
}