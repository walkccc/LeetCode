class Solution {
  public int countUnivalSubtrees(TreeNode root) {
    isUnival(root, Integer.MAX_VALUE);
    return ans;
  }

  private int ans = 0;

  private boolean isUnival(TreeNode root, int val) {
    if (root == null)
      return true;

    if (isUnival(root.left, root.val) & isUnival(root.right, root.val)) {
      ++ans;
      return root.val == val;
    }

    return false;
  }
}
