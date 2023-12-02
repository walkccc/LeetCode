public class Solution {
  public int punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      if (isPossible(0, 0, String.valueOf(i * i), 0, i))
        ans += i * i;

    return ans;
  }

  // Returns true if the sum of any split of `numChars` equals to the target.
  private boolean isPossible(int accumulate, int running, String numChars, int s, int target) {
    if (s == numChars.length())
      return target == accumulate + running;
    final int d = numChars.charAt(s) - '0';
    return isPossible(accumulate, running * 10 + d, numChars, s + 1, target) ||
        isPossible(accumulate + running, d, numChars, s + 1, target);
  }
}
