class Solution {
  // Similar to 1736. Latest Time by Replacing Hidden Digits
  public String findLatestTime(String s) {
    char[] ans = s.toCharArray();
    if (s.charAt(0) == '?')
      ans[0] = s.charAt(1) == '?' || s.charAt(1) < '2' ? '1' : '0';
    if (s.charAt(1) == '?')
      ans[1] = ans[0] == '1' ? '1' : '9';
    if (s.charAt(3) == '?')
      ans[3] = '5';
    if (s.charAt(4) == '?')
      ans[4] = '9';
    return new String(ans);
  }
}
