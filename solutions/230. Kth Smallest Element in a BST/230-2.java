class Solution {
  public int kthSmallest(TreeNode root, int k) {
    traverse(root, k);
    return ans;
  }

  private int ans = -1;
  private int rank = 0;

  private void traverse(TreeNode root, int k) {
    if (root == null)
      return;

    traverse(root.left, k);
    if (++rank == k) {
      ans = root.val;
      return;
    }
    traverse(root.right, k);
  }
}
