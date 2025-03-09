class Solution {
  public int numSimilarGroups(String[] strs) {
    int ans = 0;
    boolean[] seen = new boolean[strs.length];

    for (int i = 0; i < strs.length; ++i)
      if (!seen[i]) {
        dfs(strs, i, seen);
        ++ans;
      }

    return ans;
  }

  private void dfs(final String[] strs, int i, boolean[] seen) {
    seen[i] = true;
    for (int j = 0; j < strs.length; ++j)
      if (!seen[j] && isSimilar(strs[i], strs[j]))
        dfs(strs, j, seen);
  }

  private boolean isSimilar(final String X, final String Y) {
    int diff = 0;
    for (int i = 0; i < X.length(); ++i)
      if (X.charAt(i) != Y.charAt(i) && ++diff > 2)
        return false;
    return true;
  }
}
