class Solution {
  public List<Integer> postorderTraversal(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<Integer> ans = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      root = stack.pop();
      ans.add(root.val);
      if (root.left != null)
        stack.push(root.left);
      if (root.right != null)
        stack.push(root.right);
    }

    Collections.reverse(ans);
    return ans;
  }
}
