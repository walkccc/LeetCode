class Solution {
  public int rearrangeCharacters(String s, String target) {
    int ans = s.length();
    int[] countS = new int[128];
    int[] countT = new int[128];

    for (final char c : s.toCharArray())
      ++countS[c];

    for (final char c : target.toCharArray())
      ++countT[c];

    for (final char c : target.toCharArray())
      ans = Math.min(ans, countS[c] / countT[c]);

    return ans;
  }
}
