class Solution {
  public int countBinarySubstrings(String s) {
    int ans = 0;
    int prevCount = 0;
    int equals = 1;

    for (int i = 0; i + 1 < s.length(); ++i)
      if (s.charAt(i) == s.charAt(i + 1))
        ++equals;
      else {
        ans += Math.min(prevCount, equals);
        prevCount = equals;
        equals = 1;
      }

    return ans + Math.min(prevCount, equals);
  }
}