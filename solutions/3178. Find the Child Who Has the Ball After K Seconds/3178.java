class Solution {
  public int numberOfChild(int n, int k) {
    // the time for the ball to return to 0
    final int roundTime = 2 * (n - 1);
    final int pos = k % roundTime;
    return pos < n ? pos : roundTime - pos;
  }
}
