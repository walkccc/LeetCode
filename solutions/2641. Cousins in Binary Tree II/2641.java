class Solution {
  public TreeNode replaceValueInTree(TreeNode root) {
    List<Integer> levelSums = new ArrayList<>();
    dfs(root, 0, levelSums);
    return replace(root, 0, new TreeNode(0), levelSums);
  }

  private void dfs(TreeNode root, int level, List<Integer> levelSums) {
    if (root == null)
      return;
    if (levelSums.size() == level)
      levelSums.add(0);
    levelSums.set(level, levelSums.get(level) + root.val);
    dfs(root.left, level + 1, levelSums);
    dfs(root.right, level + 1, levelSums);
  }

  private TreeNode replace(TreeNode root, int level, TreeNode curr, List<Integer> levelSums) {
    final int nextLevel = level + 1;
    final int nextLevelCousinsSum = nextLevel >= levelSums.size()
                                        ? 0
                                        : levelSums.get(nextLevel) -
                                              (root.left == null ? 0 : root.left.val) -
                                              (root.right == null ? 0 : root.right.val);
    if (root.left != null) {
      curr.left = new TreeNode(nextLevelCousinsSum);
      replace(root.left, level + 1, curr.left, levelSums);
    }
    if (root.right != null) {
      curr.right = new TreeNode(nextLevelCousinsSum);
      replace(root.right, level + 1, curr.right, levelSums);
    }
    return curr;
  }
}
