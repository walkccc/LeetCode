class Solution {
  public boolean isPrefixString(String s, String[] words) {
    StringBuilder sb = new StringBuilder();
    for (final String word : words) {
      sb.append(word);
      // Do not call `toString()` unless the length matches.
      if (sb.length() == s.length() && sb.toString().equals(s))
        return true;
    }
    return false;
  }
}
