class BSTIterator {
  BSTIterator(TreeNode root, boolean leftToRight) {
    this.leftToRight = leftToRight;
    pushUntilNull(root);
  }

  public boolean hasNext() {
    return !stack.isEmpty();
  }

  public int next() {
    TreeNode root = stack.pop();
    pushUntilNull(leftToRight ? root.right : root.left);
    return root.val;
  }

  private Deque<TreeNode> stack = new ArrayDeque<>();
  private boolean leftToRight;

  private void pushUntilNull(TreeNode root) {
    while (root != null) {
      stack.push(root);
      root = leftToRight ? root.left : root.right;
    }
  }
}

class Solution {
  public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
    BSTIterator bst1 = new BSTIterator(root1, true);
    BSTIterator bst2 = new BSTIterator(root2, false);

    for (int l = bst1.next(), r = bst2.next(); true;) {
      final int sum = l + r;
      if (sum == target)
        return true;
      if (sum < target) {
        if (!bst1.hasNext())
          return false;
        l = bst1.next();
      } else {
        if (!bst2.hasNext())
          return false;
        r = bst2.next();
      }
    }
  }
}
