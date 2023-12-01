class Solution {
  public List<List<String>> printTree(TreeNode root) {
    final int m = maxHeight(root);
    final int n = (int) Math.pow(2, m) - 1;
    List<List<String>> ans = new ArrayList<>();
    List<String> row = new ArrayList<>();

    for (int i = 0; i < n; ++i)
      row.add("");

    for (int i = 0; i < m; ++i)
      ans.add(new ArrayList<>(row));

    dfs(root, 0, 0, n - 1, ans);
    return ans;
  }

  private int maxHeight(TreeNode root) {
    if (root == null)
      return 0;
    return 1 + Math.max(maxHeight(root.left), maxHeight(root.right));
  }

  private void dfs(TreeNode root, int row, int left, int right, List<List<String>> ans) {
    if (root == null)
      return;

    final int mid = (left + right) / 2;
    ans.get(row).set(mid, Integer.toString(root.val));
    dfs(root.left, row + 1, left, mid - 1, ans);
    dfs(root.right, row + 1, mid + 1, right, ans);
  }
}
