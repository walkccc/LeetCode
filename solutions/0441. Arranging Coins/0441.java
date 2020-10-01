class Solution {
  public int arrangeCoins(long n) {
    return (int) (-1 + Math.sqrt(8 * n + 1)) / 2;
  }
}