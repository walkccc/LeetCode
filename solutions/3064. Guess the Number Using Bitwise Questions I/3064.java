/**
 * Definition of commonSetBits API (defined in the parent class Problem).
 * int commonSetBits(int num);
 */

public class Solution extends Problem {
  public int findNumber() {
    final int MAX_BIT = 30;
    int ans = 0;
    for (int i = 0; i <= MAX_BIT; ++i)
      if (commonSetBits(1 << i) == 1)
        ans |= 1 << i;
    return ans;
  }
}
