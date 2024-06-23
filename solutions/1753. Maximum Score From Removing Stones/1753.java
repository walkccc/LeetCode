class Solution {
  public int maximumScore(int a, int b, int c) {
    // the maximum <= the minimum + the middle
    final int x = (a + b + c) / 2;
    // the maximum > the minimum + the middle
    final int y = a + b + c - Math.max(a, Math.max(b, c));
    return Math.min(x, y);
  }
}
