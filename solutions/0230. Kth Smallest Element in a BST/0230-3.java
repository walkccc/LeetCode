class Solution {
  public int kthSmallest(TreeNode root, int k) {
    Stack<TreeNode> stack = new Stack<>();

    while (root != null) {
      stack.push(root);
      root = root.left;
    }

    for (int i = 0; i < k - 1; ++i) {
      root = stack.pop();
      root = root.right;
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
    }

    return stack.peek().val;
  }
}
