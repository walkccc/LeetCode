class Solution {
  public int getMinimumDifference(TreeNode root) {
    // very similar to 94. Binary Tree Inorder Traversal
    int ans = Integer.MAX_VALUE;
    int prev = -1;
    Stack<TreeNode> stack = new Stack<>();

    while (root != null || !stack.isEmpty()) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      if (prev >= 0)
        ans = Math.min(ans, root.val - prev);
      prev = root.val;
      root = root.right;
    }

    return ans;
  }
}
