class Solution {
  public long numberOfSubstrings(String s) {
    long ans = 0;
    int[] count = new int[128];

    for (final char c : s.toCharArray()) {
      ans += count[c] + 1;
      ++count[c];
    }

    return ans;
  }
}
