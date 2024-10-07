class Solution {
  public int appendCharacters(String s, String t) {
    int i = 0; // t's index

    for (final char c : s.toCharArray())
      if (c == t.charAt(i))
        if (++i == t.length())
          return 0;

    return t.length() - i;
  }
}
