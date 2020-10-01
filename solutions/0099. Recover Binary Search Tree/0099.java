class Solution {
  public void recoverTree(TreeNode root) {
    inorder(root);
    final int temp = first.val;
    first.val = second.val;
    second.val = temp;
  }

  private TreeNode pred = new TreeNode(Integer.MIN_VALUE);
  private TreeNode first = null;
  private TreeNode second = null;

  private void inorder(TreeNode root) {
    if (root == null)
      return;

    inorder(root.left);

    if (first == null && pred.val > root.val)
      first = pred;
    if (first != null && pred.val > root.val)
      second = root;
    pred = root;

    inorder(root.right);
  }
}