class Solution {
  public TreeNode insertIntoMaxTree(TreeNode root, int val) {
    if (root.val < val)
      return new TreeNode(val, root, null);
    TreeNode curr = root;
    while (curr.right != null && curr.right.val > val)
      curr = curr.right;
    TreeNode inserted = new TreeNode(val, curr.right, null);
    curr.right = inserted;
    return root;
  }
}
