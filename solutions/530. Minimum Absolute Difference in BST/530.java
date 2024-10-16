class Solution {
  // Similar to 94. Binary Tree Inorder Traversal
  public int getMinimumDifference(TreeNode root) {
    int ans = Integer.MAX_VALUE;
    int prev = -1;
    Deque<TreeNode> stack = new ArrayDeque<>();

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
