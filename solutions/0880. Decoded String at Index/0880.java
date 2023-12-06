class Solution {
  public String decodeAtIndex(String s, int k) {
    long size = 0; // the length of the decoded `s`

    for (final char c : s.toCharArray())
      if (Character.isDigit(c))
        size *= c - '0';
      else
        ++size;

    for (int i = s.length() - 1; i >= 0; --i) {
      k %= size;
      if (k == 0 && Character.isAlphabetic(s.charAt(i)))
        return s.substring(i, i + 1);
      if (Character.isDigit(s.charAt(i)))
        size /= s.charAt(i) - '0';
      else
        --size;
    }

    throw new IllegalArgumentException();
  }
}
