class Solution {
  public long maximumSubsequenceCount(String text, String pattern) {
    long ans = 0;
    int count0 = 0;
    int count1 = 0;

    for (int i = 0; i < text.length(); ++i) {
      if (text.charAt(i) == pattern.charAt(1)) {
        ans += count0;
        ++count1;
      }
      if (text.charAt(i) == pattern.charAt(0))
        ++count0;
    }

    // adding pattern.charAt(0) in the beginning or
    // adding pattern.charAt(1) in the end is optimal
    return ans + Math.max(count0, count1);
  }
}
