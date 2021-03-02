class Solution {
  public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();

    while (root != null || !stack.isEmpty()) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      ans.add(root.val);
      root = root.right;
    }

    return ans;
  }
}
