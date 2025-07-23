class Solution {
  public char findTheDifference(String s, String t) {
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (final char c : t.toCharArray()) {
      if (count[c - 'a'] == 0)
        return c;
      --count[c - 'a'];
    }

    throw new IllegalArgumentException();
  }
}
