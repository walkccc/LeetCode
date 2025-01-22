class Solution {
  public int maxRemovals(String source, String pattern, int[] targetIndices) {
    Set<Integer> target = Arrays.stream(targetIndices).boxed().collect(Collectors.toSet());
    Integer[][] mem = new Integer[source.length()][pattern.length()];
    final int ans = maxRemovals(source, pattern, 0, 0, target, mem);
    return ans == Integer.MIN_VALUE ? 0 : ans;
  }

  // Returns the maximum number of operations that can be performed for
  // source[i..m) and pattern[j..n).
  private int maxRemovals(String source, String pattern, int i, int j, Set<Integer> target,
                          Integer[][] mem) {
    if (i == source.length())
      return j == pattern.length() ? 0 : Integer.MIN_VALUE;
    if (j == pattern.length())
      return (target.contains(i) ? 1 : 0) + maxRemovals(source, pattern, i + 1, j, target, mem);
    if (mem[i][j] != null)
      return mem[i][j];
    final int pick = source.charAt(i) == pattern.charAt(j)
                         ? maxRemovals(source, pattern, i + 1, j + 1, target, mem)
                         : Integer.MIN_VALUE;
    final int skip =
        (target.contains(i) ? 1 : 0) + maxRemovals(source, pattern, i + 1, j, target, mem);
    return mem[i][j] = Math.max(pick, skip);
  }
}
