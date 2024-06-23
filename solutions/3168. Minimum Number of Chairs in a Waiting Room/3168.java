class Solution {
  public int minimumChairs(String s) {
    int ans = 0;
    int chairs = 0;

    for (final char c : s.toCharArray()) {
      chairs += c == 'E' ? 1 : -1;
      ans = Math.max(ans, chairs);
    }

    return ans;
  }
}
