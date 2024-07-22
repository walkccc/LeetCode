class BSTIterator {
  public BSTIterator(TreeNode root, boolean leftToRight) {
    this.leftToRight = leftToRight;
    pushLeftsUntilNull(root);
  }

  public int next() {
    TreeNode root = stack.pop();
    pushLeftsUntilNull(leftToRight ? root.right : root.left);
    return root.val;
  }

  public boolean hasNext() {
    return !stack.isEmpty();
  }

  private Deque<TreeNode> stack = new ArrayDeque<>();
  private boolean leftToRight;

  private void pushLeftsUntilNull(TreeNode root) {
    while (root != null) {
      stack.push(root);
      root = leftToRight ? root.left : root.right;
    }
  }
}

class Solution {
  public boolean findTarget(TreeNode root, int k) {
    if (root == null)
      return false;

    BSTIterator left = new BSTIterator(root, true);
    BSTIterator right = new BSTIterator(root, false);

    for (int l = left.next(), r = right.next(); l < r;) {
      final int sum = l + r;
      if (sum == k)
        return true;
      if (sum < k)
        l = left.next();
      else
        r = right.next();
    }

    return false;
  }
}
