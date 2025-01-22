class Solution {
  public int scoreOfString(String s) {
    int ans = 0;

    for (int i = 1; i < s.length(); ++i)
      ans += Math.abs(s.charAt(i) - s.charAt(i - 1));

    return ans;
  }
}
