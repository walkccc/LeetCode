class Solution {
  public List<Boolean> camelMatch(String[] queries, String pattern) {
    List<Boolean> ans = new ArrayList<>();

    for (final String query : queries)
      ans.add(isMatch(query, pattern));

    return ans;
  }

  private boolean isMatch(final String query, final String pattern) {
    int j = 0;

    for (int i = 0; i < query.length(); ++i)
      if (j < pattern.length() && query.charAt(i) == pattern.charAt(j))
        ++j;
      else if (Character.isUpperCase(query.charAt(i)))
        return false;

    return j == pattern.length();
  }
}
