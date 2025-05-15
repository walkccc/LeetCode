class Solution {
  // Similar to 1161. Maximum Level Sum of a Binary Tree
  public int minimumLevel(TreeNode root) {
    // levelSums[i] := the sum of level (i + 1) (1-indexed)
    List<Long> levelSums = new ArrayList<>();
    dfs(root, 0, levelSums);
    return 1 + IntStream.range(0, levelSums.size())
                   .reduce(0, (a, b) -> levelSums.get(a) > levelSums.get(b) ? b : a);
  }

  private void dfs(TreeNode root, int level, List<Long> levelSums) {
    if (root == null)
      return;
    if (levelSums.size() == level)
      levelSums.add(0L);
    levelSums.set(level, levelSums.get(level) + root.val);
    dfs(root.left, level + 1, levelSums);
    dfs(root.right, level + 1, levelSums);
  }
}
