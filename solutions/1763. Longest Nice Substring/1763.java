class Solution {
  public String longestNiceSubstring(String s) {
    if (s.length() < 2)
      return "";

    Set<Character> seen = s.chars().mapToObj(c -> (char) c).collect(Collectors.toSet());

    for (int i = 0; i < s.length(); ++i)
      if (!seen.contains(toggleCase(s.charAt(i)))) {
        final String prefix = longestNiceSubstring(s.substring(0, i));
        final String suffix = longestNiceSubstring(s.substring(i + 1));
        return prefix.length() >= suffix.length() ? prefix : suffix;
      }

    return s;
  }

  private char toggleCase(char c) {
    return Character.isLowerCase(c) ? Character.toUpperCase(c) : Character.toLowerCase(c);
  }
}
