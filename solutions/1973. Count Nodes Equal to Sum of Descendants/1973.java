class Solution {
  public int equalToDescendants(TreeNode root) {
    return dfs(root).count;
  }

  private T dfs(TreeNode root) {
    if (root == null)
      return new T(0, 0);
    T left = dfs(root.left);
    T right = dfs(root.right);
    return new T(root.val + left.sum + right.sum,
                 left.count + right.count + (root.val == left.sum + right.sum ? 1 : 0));
  }

  private record T(long sum, int count){};
}
