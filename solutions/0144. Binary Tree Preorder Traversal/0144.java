class Solution {
  public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    preorder(root, ans);
    return ans;
  }

  private void preorder(TreeNode root, List<Integer> ans) {
    if (root == null)
      return;

    ans.add(root.val);
    preorder(root.left, ans);
    preorder(root.right, ans);
  }
}
