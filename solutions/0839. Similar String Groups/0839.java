class Solution {
  public int numSimilarGroups(String[] A) {
    int ans = 0;
    boolean[] seen = new boolean[A.length];

    for (int i = 0; i < A.length; ++i)
      if (!seen[i]) {
        dfs(A, i, seen);
        ++ans;
      }

    return ans;
  }

  private void dfs(final String[] A, int i, boolean[] seen) {
    seen[i] = true;
    for (int j = 0; j < A.length; ++j)
      if (!seen[j] && isSimilar(A[i], A[j]))
        dfs(A, j, seen);
  }

  private boolean isSimilar(final String X, final String Y) {
    int diff = 0;
    for (int i = 0; i < X.length(); ++i)
      if (X.charAt(i) != Y.charAt(i) && ++diff > 2)
        return false;
    return true;
  }
}
