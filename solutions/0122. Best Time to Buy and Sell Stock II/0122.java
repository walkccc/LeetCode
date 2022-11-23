class Solution {
  public int maxProfit(int[] prices) {
    int sell = 0;
    int hold = Integer.MIN_VALUE;

    for (final int price : prices) {
      sell = Math.max(sell, hold + price);
      hold = Math.max(hold, sell - price);
    }

    return sell;
  }
}
