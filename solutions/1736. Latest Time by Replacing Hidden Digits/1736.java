class Solution {
  public String maximumTime(String time) {
    char[] ans = time.toCharArray();
    if (time.charAt(0) == '?')
      ans[0] = time.charAt(1) == '?' || time.charAt(1) < '4' ? '2' : '1';
    if (time.charAt(1) == '?')
      ans[1] = ans[0] == '2' ? '3' : '9';
    if (time.charAt(3) == '?')
      ans[3] = '5';
    if (time.charAt(4) == '?')
      ans[4] = '9';
    return new String(ans);
  }
}
