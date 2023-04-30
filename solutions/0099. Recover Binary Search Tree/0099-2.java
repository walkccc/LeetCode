class Solution {
  public void recoverTree(TreeNode root) {
    TreeNode pred = null;
    TreeNode x = null;
    TreeNode y = null;

    Deque<TreeNode> stack = new ArrayDeque<>();

    while (root != null || !stack.isEmpty()) {
      while (root != null) {
        stack.add(root);
        root = root.left;
      }
      root = stack.pollLast();
      if (pred != null && root.val < pred.val) {
        y = root;
        if (x == null)
          x = pred;
      }
      pred = root;
      root = root.right;
    }

    swap(x, y);
  }

  private void swap(TreeNode x, TreeNode y) {
    final int temp = x.val;
    x.val = y.val;
    y.val = temp;
  }
}
