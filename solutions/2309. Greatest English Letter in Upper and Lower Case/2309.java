class Solution {
  public String greatestLetter(String s) {
    boolean[] seen = new boolean[128];

    for (final char c : s.toCharArray())
      seen[c] = true;

    for (int i = 25; i >= 0; --i)
      if (seen['a' + i] && seen['A' + i])
        return String.valueOf((char) ('A' + i));

    return "";
  }
}
