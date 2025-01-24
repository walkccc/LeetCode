class Solution {
  public int findTheLongestBalancedSubstring(String s) {
    int ans = 0;
    int zeros = 0;
    int ones = 0;

    for (final char c : s.toCharArray()) {
      if (c == '0') {
        zeros = ones > 0 ? 1 : zeros + 1;
        ones = 0;
      } else { // c == '1'
        ++ones;
      }
      if (zeros >= ones)
        ans = Math.max(ans, ones);
    }

    return ans * 2;
  }
}
