class Solution {
  public String findValidPair(String s) {
    int[] count = new int[10];

    for (final char c : s.toCharArray())
      ++count[c - '0'];

    for (int i = 0; i < s.length() - 1; ++i) {
      final int a = s.charAt(i) - '0';
      final int b = s.charAt(i + 1) - '0';
      if (a != b && count[a] == a && count[b] == b)
        return s.substring(i, i + 2);
    }

    return "";
  }
}
