class Solution {
  public int[] simulationResult(int[] windows, int[] queries) {
    int[] ans = new int[windows.length];
    int ansIndex = 0;
    Set<Integer> seen = new HashSet<>();

    for (int i = queries.length - 1; i >= 0; --i)
      if (!seen.contains(queries[i])) {
        ans[ansIndex++] = queries[i];
        seen.add(queries[i]);
      }

    for (final int window : windows)
      if (!seen.contains(window)) {
        ans[ansIndex++] = window;
        seen.add(window);
      }

    return ans;
  }
}
