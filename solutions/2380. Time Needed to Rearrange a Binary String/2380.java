class Solution {
  public int secondsToRemoveOccurrences(String s) {
    int ans = 0;
    int zeros = 0;

    for (final char c : s.toCharArray())
      if (c == '0')
        ++zeros;
      else if (zeros > 0) // c == '1'
        ans = Math.max(ans + 1, zeros);

    return ans;
  }
}
