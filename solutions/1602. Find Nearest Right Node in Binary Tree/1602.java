class Solution {
  public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
    dfs(root, u, 0);
    return ans;
  }

  private TreeNode ans = null;
  private int targetDepth = -1;

  private void dfs(TreeNode root, TreeNode u, int depth) {
    if (root == null)
      return;
    if (root == u) {
      targetDepth = depth;
      return;
    }
    if (depth == targetDepth && ans == null) {
      ans = root;
      return;
    }
    dfs(root.left, u, depth + 1);
    dfs(root.right, u, depth + 1);
  }
}
