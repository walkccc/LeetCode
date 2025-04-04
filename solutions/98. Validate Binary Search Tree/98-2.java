class Solution {
  public boolean isValidBST(TreeNode root) {
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode pred = null;

    while (root != null || !stack.isEmpty()) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      if (pred != null && pred.val >= root.val)
        return false;
      pred = root;
      root = root.right;
    }

    return true;
  }
}
