public class Solution {
  public int numWays(String s) {
    final int kMod = 1_000_000_007;
    final int ones = (int) s.chars().filter(c -> c == '1').count();
    if (ones % 3 != 0)
      return 0;
    if (ones == 0) {
      final long n = s.length();
      return (int) ((n - 1) * (n - 2) / 2 % kMod);
    }

    int s1End = -1;
    int s2Start = -1;
    int s2End = -1;
    int s3Start = -1;
    int onesSoFar = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (s.charAt(i) == '1')
        ++onesSoFar;
      if (s1End == -1 && onesSoFar == ones / 3)
        s1End = i;
      else if (s2Start == -1 && onesSoFar == ones / 3 + 1)
        s2Start = i;
      if (s2End == -1 && onesSoFar == ones / 3 * 2)
        s2End = i;
      else if (s3Start == -1 && onesSoFar == ones / 3 * 2 + 1)
        s3Start = i;
    }

    return (int) ((long) (s2Start - s1End) * (s3Start - s2End) % kMod);
  }
}
