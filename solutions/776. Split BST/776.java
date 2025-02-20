class Solution {
  public TreeNode[] splitBST(TreeNode root, int target) {
    if (root == null)
      return new TreeNode[] {null, null};
    if (root.val > target) {
      TreeNode[] res = splitBST(root.left, target);
      root.left = res[1];
      return new TreeNode[] {res[0], root};
    } else { // root.val <= target
      TreeNode[] res = splitBST(root.right, target);
      root.right = res[0];
      return new TreeNode[] {root, res[1]};
    }
  }
}
