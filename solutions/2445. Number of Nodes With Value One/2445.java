class Solution {
  public int numberOfNodes(int n, int[] queries) {
    // flipped[i] := true if we should flip all the values in the subtree rooted
    // at i
    boolean[] flipped = new boolean[n + 1];

    for (final int query : queries)
      flipped[query] = flipped[query] ^ true;

    return dfs(1, 0, n, flipped);
  }

  private int dfs(int label, int value, int n, boolean[] flipped) {
    if (label > n)
      return 0;
    value ^= flipped[label] ? 1 : 0;
    return value +                          //
        dfs(label * 2, value, n, flipped) + //
        dfs(label * 2 + 1, value, n, flipped);
  }
}
