class Solution {
  public long maximumSubsequenceCount(String text, String pattern) {
    long ans = 0;
    int count0 = 0; // the count of the letter pattern[0]
    int count1 = 0; // the count of the letter pattern[1]

    for (final char c : text.toCharArray()) {
      if (c == pattern.charAt(1)) {
        ans += count0;
        ++count1;
      }
      if (c == pattern.charAt(0))
        ++count0;
    }

    // It is optimal to add pattern[0] at the beginning or add pattern[1] at the
    // end of the text.
    return ans + Math.max(count0, count1);
  }
}
