class Solution {
  public int averageOfSubtree(TreeNode root) {
    dfs(root);
    return ans;
  }

  private int ans = 0;

  private Pair<Integer, Integer> dfs(TreeNode root) {
    if (root == null)
      return new Pair<>(0, 0);
    Pair<Integer, Integer> left = dfs(root.left);
    Pair<Integer, Integer> right = dfs(root.right);
    final int sum = root.val + left.getKey() + right.getKey();
    final int count = 1 + left.getValue() + right.getValue();
    if (sum / count == root.val)
      ++ans;
    return new Pair<>(sum, count);
  }
}
