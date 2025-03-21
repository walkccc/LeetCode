class Solution {
  public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
    Set<Long> blockedSet = new HashSet<>();
    for (int[] b : blocked)
      blockedSet.add(hash(b[0], b[1]));

    return dfs(blockedSet, source[0], source[1], hash(target[0], target[1]), new HashSet<>()) &&
        dfs(blockedSet, target[0], target[1], hash(source[0], source[1]), new HashSet<>());
  }

  private boolean dfs(Set<Long> blockedSet, int i, int j, long target, Set<Long> seen) {
    if (i < 0 || i >= 1e6 || j < 0 || j >= 1e6 || blockedSet.contains(hash(i, j)) ||
        seen.contains(hash(i, j)))
      return false;

    seen.add(hash(i, j));
    if (seen.size() > (1 + 199) * 199 / 2 || hash(i, j) == target)
      return true;

    return                                         //
        dfs(blockedSet, i + 1, j, target, seen) || //
        dfs(blockedSet, i - 1, j, target, seen) || //
        dfs(blockedSet, i, j + 1, target, seen) || //
        dfs(blockedSet, i, j - 1, target, seen);
  }

  private long hash(int i, int j) {
    return ((long) i << 16) + j;
  }
}
