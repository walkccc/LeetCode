class Solution {
  public List<Integer> rightSideView(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    dfs(root, 0, ans);
    return ans;
  }

  private void dfs(TreeNode root, int depth, List<Integer> ans) {
    if (root == null)
      return;

    if (depth == ans.size())
      ans.add(root.val);
    dfs(root.right, depth + 1, ans);
    dfs(root.left, depth + 1, ans);
  }
}
