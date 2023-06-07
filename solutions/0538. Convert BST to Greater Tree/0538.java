class Solution {
  public TreeNode convertBST(TreeNode root) {
    reversedInorder(root);
    return root;
  }

  private int prefix = 0;

  private void reversedInorder(TreeNode root) {
    if (root == null)
      return;

    reversedInorder(root.right);
    prefix += root.val;
    root.val = prefix;
    reversedInorder(root.left);
  }
}
