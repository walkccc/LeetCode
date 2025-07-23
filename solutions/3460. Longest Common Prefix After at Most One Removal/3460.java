class Solution {
  public int longestCommonPrefix(String s, String t) {
    int i = 0; // s's index
    int j = 0; // t's index
    boolean canSkip = true;

    while (i < s.length() && j < t.length())
      if (s.charAt(i) == t.charAt(j)) {
        ++i;
        ++j;
      } else if (canSkip) {
        ++i;
        canSkip = false;
      } else {
        return j;
      }

    return j;
  }
}
