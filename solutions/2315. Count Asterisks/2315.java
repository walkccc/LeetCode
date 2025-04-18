class Solution {
  public int countAsterisks(String s) {
    int ans = 0;
    int bars = 0;

    for (final char c : s.toCharArray()) {
      if (c == '|')
        ++bars;
      else if (c == '*' && bars % 2 == 0)
        ++ans;
    }

    return ans;
  }
}
