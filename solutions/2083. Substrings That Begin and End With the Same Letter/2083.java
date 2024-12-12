class Solution {
  public long numberOfSubstrings(String s) {
    long ans = 0;
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ans += ++count[c - 'a'];

    return ans;
  }
}
