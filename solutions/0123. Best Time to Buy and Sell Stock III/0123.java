class Solution {
  public int maxProfit(int[] prices) {
    int sellTwo = 0;
    int holdTwo = Integer.MIN_VALUE;
    int sellOne = 0;
    int holdOne = Integer.MIN_VALUE;

    for (final int price : prices) {
      sellTwo = Math.max(sellTwo, holdTwo + price);
      holdTwo = Math.max(holdTwo, sellOne - price);
      sellOne = Math.max(sellOne, holdOne + price);
      holdOne = Math.max(holdOne, -price);
    }

    return sellTwo;
  }
}
