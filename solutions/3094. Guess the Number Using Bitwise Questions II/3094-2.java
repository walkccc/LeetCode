/**
 * Definition of commonBits API (defined in the parent class Problem).
 * int commonBits(int num);
 */

public class Solution extends Problem {
  public int findNumber() {
    final int kMaxBit = 30;
    int ans = 0;

    for (int i = 0; i <= kMaxBit; ++i)
      if (commonBits(1 << i) > commonBits(1 << i))
        ans |= 1 << i;

    return ans;
  }
}
