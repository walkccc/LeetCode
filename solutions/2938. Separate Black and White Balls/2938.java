class Solution {
  public long minimumSteps(String s) {
    long ans = 0;
    int ones = 0;

    for (final char c : s.toCharArray())
      if (c == '1')
        ++ones;
      else // Move `ones` to the front of current '0'.
        ans += ones;

    return ans;
  }
}
