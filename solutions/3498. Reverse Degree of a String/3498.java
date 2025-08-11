class Solution {
  public int reverseDegree(String s) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      final int reversePos = 26 - (s.charAt(i) - 'a');
      ans += reversePos * (i + 1);
    }
    return ans;
  }
}
