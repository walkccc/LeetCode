class Solution {
  public int minOperations(int n) {
    // The strategy is that when the end of n is
    //   1. consecutive 1s, add 1 (2^0).
    //   2. single 1, substract 1 (2^0).
    //   3. 0, substract 2^k to omit the last 1. Equivalently, n >> 1.
    //
    // e.g.
    //
    //         n = 0b101
    // n -= 2^0 -> 0b100
    // n -= 2^2 -> 0b0
    //         n = 0b1011
    // n += 2^0 -> 0b1100
    // n -= 2^2 -> 0b1000
    // n -= 2^3 -> 0b0
    int ans = 0;

    while (n > 0)
      if ((n & 3) == 3) {
        ++n;
        ++ans;
      } else if ((n & 1) == 1) {
        --n;
        ++ans;
      } else {
        n >>= 1;
      }

    return ans;
  }
}
