class Solution {
  public int buyChoco(int[] prices, int money) {
    int min1 = Integer.MAX_VALUE;
    int min2 = Integer.MAX_VALUE;

    for (final int price : prices)
      if (price <= min1) {
        min2 = min1;
        min1 = price;
      } else if (price < min2) {
        min2 = price;
      }

    final int minCost = min1 + min2;
    return minCost > money ? money : money - minCost;
  }
}
