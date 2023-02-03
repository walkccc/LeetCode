class Solution {
  public boolean isAlienSorted(String[] words, String order) {
    char[] map = new char[26]; // Order = "bca" -> map = ['c', 'a', 'b']

    for (int i = 0; i < 26; ++i)
      map[order.charAt(i) - 'a'] = (char) (i + 'a');

    for (int i = 0; i + 1 < words.length; ++i)
      if (bigger(words[i], words[i + 1], map))
        return false;

    return true;
  }

  private boolean bigger(final String s1, final String s2, final char[] map) {
    for (int i = 0; i < s1.length() && i < s2.length(); ++i)
      if (s1.charAt(i) != s2.charAt(i))
        return map[s1.charAt(i) - 'a'] > map[s2.charAt(i) - 'a'];
    return s1.length() > s2.length();
  }
}
