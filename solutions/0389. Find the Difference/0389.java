class Solution {
  public char findTheDifference(String s, String t) {
    char ans = 0;

    for (final char c : s.toCharArray())
      ans ^= c;

    for (final char c : t.toCharArray())
      ans ^= c;

    return ans;
  }
}
