class Solution {
  public String encode(String s) {
    final int n = s.length();
    String[][] mem = new String[n][n];
    return encode(s, 0, n - 1, mem);
  }

  // Returns the shortest encoded string of s[i..j].
  private String encode(final String s, int i, int j, String[][] mem) {
    if (mem[i][j] != null)
      return mem[i][j];

    final String curr = s.substring(i, j + 1);
    mem[i][j] = curr;

    if (mem[i][j].length() < 5)
      return mem[i][j];

    // Try all the possible partitions.
    for (int k = i; k < j; ++k) {
      final String l = encode(s, i, k, mem);
      final String r = encode(s, k + 1, j, mem);
      if (l.length() + r.length() < mem[i][j].length())
        mem[i][j] = l + r;
    }

    // Try to compress the string.
    // e.g. s = aabaabaab -> 3[aab]
    for (int k = i; k <= j; ++k) {
      final String pattern = s.substring(i, k + 1);
      if (curr.length() % pattern.length() == 0 && curr.replaceAll(pattern, "").isEmpty()) {
        final String candidate =
            String.valueOf(curr.length() / pattern.length()) + "[" + encode(s, i, k, mem) + "]";
        if (candidate.length() < mem[i][j].length())
          mem[i][j] = candidate;
      }
    }

    return mem[i][j];
  }
}
