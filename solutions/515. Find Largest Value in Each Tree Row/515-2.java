class Solution {
  public List<Integer> largestValues(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    dfs(root, 0, ans);
    return ans;
  }

  private void dfs(TreeNode root, int depth, List<Integer> ans) {
    if (root == null)
      return;
    if (depth + 1 > ans.size())
      ans.add(root.val);
    else
      ans.set(depth, Math.max(ans.get(depth), root.val));

    dfs(root.left, depth + 1, ans);
    dfs(root.right, depth + 1, ans);
  }
}
