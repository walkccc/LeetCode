class Solution {
  public boolean wordPatternMatch(String pattern, String s) {
    return isMatch(pattern, 0, s, 0, new HashMap<>(), new HashSet<>());
  }

  private boolean isMatch(final String pattern, int i, final String s, int j,
                          Map<Character, String> charToString, Set<String> seen) {
    if (i == pattern.length() && j == s.length())
      return true;
    if (i == pattern.length() || j == s.length())
      return false;

    final char c = pattern.charAt(i);

    if (charToString.containsKey(c)) {
      final String t = charToString.get(c);
      // See if we can match t with s[j..n).
      if (!s.startsWith(t, j))
        return false;

      // If there's a match, continue to match the rest.
      return isMatch(pattern, i + 1, s, j + t.length(), charToString, seen);
    }

    for (int k = j; k < s.length(); ++k) {
      final String t = s.substring(j, k + 1);

      // This string is mapped by another character.
      if (seen.contains(t))
        continue;

      charToString.put(c, t);
      seen.add(t);

      if (isMatch(pattern, i + 1, s, k + 1, charToString, seen))
        return true;

      // Backtrack.
      charToString.remove(c);
      seen.remove(t);
    }

    return false;
  }
}
