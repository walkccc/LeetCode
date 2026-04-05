class Solution {
  public int sumOfLeftLeaves(TreeNode root) {
    if (root == null)
      return 0;

    int ans = 0;
    Deque<TreeNode> stack = new ArrayDeque<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      root = stack.pop();
      if (root.left != null) {
        if (root.left.left == null && root.left.right == null)
          ans += root.left.val;
        else
          stack.push(root.left);
      }
      if (root.right != null)
        stack.push(root.right);
    }

    return ans;
  }
}
