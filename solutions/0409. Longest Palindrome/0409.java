class Solution {
  public int longestPalindrome(String s) {
    int ans = 0;
    int[] count = new int[128];

    for (final char c : s.toCharArray())
      ++count[c];

    for (final int c : count)
      ans += c % 2 == 0 ? c : c - 1;

    final boolean hasOddCount = Arrays.stream(count).anyMatch(c -> c % 2 == 1);

    return ans + (hasOddCount ? 1 : 0);
  }
}
