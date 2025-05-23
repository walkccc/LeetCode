/**
 * Definition of commonBits API (defined in the parent class Problem).
 * int commonBits(int num);
 */

public class Solution extends Problem {
  public int findNumber() {
    final int MAX_BIT = 30;
    final int sameCount = commonBits(0);
    int ans = 0;

    for (int i = 0; i <= MAX_BIT; ++i) {
      if (commonBits(1 << i) > sameCount)
        ans |= 1 << i;
      commonBits(1 << i); // Revert the XOR.
    }

    return ans;
  }
}
