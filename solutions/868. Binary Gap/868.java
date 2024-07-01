class Solution {
  public int binaryGap(int n) {
    int ans = 0;

    // d := the distance between any two 1s
    for (int d = -32; n > 0; n /= 2, ++d)
      if ((n & 1) == 1) {
        ans = Math.max(ans, d);
        d = 0;
      }

    return ans;
  }
}
