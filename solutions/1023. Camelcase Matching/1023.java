class Solution {
  public List<Boolean> camelMatch(String[] queries, String pattern) {
    List<Boolean> ans = new ArrayList<>();

    for (final String q : queries)
      ans.add(isMatch(q, pattern));

    return ans;
  }

  private boolean isMatch(final String q, final String pattern) {
    int j = 0;

    for (int i = 0; i < q.length(); ++i)
      if (j < pattern.length() && q.charAt(i) == pattern.charAt(j))
        ++j;
      else if (Character.isUpperCase(q.charAt(i)))
        return false;

    return j == pattern.length();
  }
}
