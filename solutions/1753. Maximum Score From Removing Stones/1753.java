class Solution {
  public int maximumScore(int a, int b, int c) {
    // Max <= min + mid
    final int x = (a + b + c) / 2;
    // Max > min + mid
    final int y = a + b + c - Math.max(a, Math.max(b, c));
    return Math.min(x, y);
  }
}
