class Solution {
  public boolean evaluateTree(TreeNode root) {
    if (root.val < 2)
      return root.val == 1;
    if (root.val == 2) // OR
      return evaluateTree(root.left) || evaluateTree(root.right);
    // AND
    return evaluateTree(root.left) && evaluateTree(root.right);
  }
}
