class Solution {
  public List<Boolean> camelMatch(String[] queries, String pattern) {
    List<Boolean> ans = new ArrayList<>();
    for (final String query : queries)
      ans.add(isMatch(query, pattern));
    return ans;
  }

  private boolean isMatch(final String query, final String pattern) {
    int j = 0;
    for (final char c : query.toCharArray())
      if (j < pattern.length() && c == pattern.charAt(j))
        ++j;
      else if (Character.isUpperCase(c))
        return false;
    return j == pattern.length();
  }
}
